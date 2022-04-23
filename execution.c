#include"minishell.h"
int    exec_cmd(t_tree *tree, char **env, int ou , int in)
{
    int pid = fork();
    if(pid == 0)
    {
        dup2(ou,1);
        if (ou != 1)
            close(ou);
        dup2(in,0);
        if (in != 0)
            close(in);
        if(execve(tree->cmd->path, ft_path_split(tree->cmd->name, ' '), env) == -1)
        {
            ft_putstr_fd("Minishell: ", 2);
            ft_putstr_fd(tree->cmd->name, 2);
            ft_putstr_fd(": command not found\n", 2);
			return(3);
        }
    }
    else
    {
        if (in != 0)
            close(in);
        wait(NULL);
    }
    return(1);
}
int    ft_execution(t_tree *tree, char **env, int ou , int in)
{
    if(!tree)
        exit(5);
    int	p[2];
    int fd_out;
    int fd_in = 0;
    int fd_tmp = 0;
    int fd_tmp2;
    t_tree *tree_tmp = NULL;
    pipe(p);

    if(tree->op != NULL)
    {
        if(ft_strcmp(tree->op,"&&") == 0)
        {
            ft_execution(tree->branch1, env , ou, in);
            ft_execution(tree->branch2, env, ou, in);
        }
        else if(ft_strcmp(tree->op, "||") == 0)
        {
            if(ft_execution(tree->branch1, env, ou , in) == 3)
                ft_execution(tree->branch2, env, ou , in);
        }
        else if(ft_strcmp(tree->op, "|") == 0)
        {
            if(ft_execution(tree->branch1, env , p[1],in) == 3)
                exit(1);
            close(p[1]);
            if(ft_execution(tree->branch2, env, ou , p[0]) == 3)
                exit(1);
            close(p[0]);
        }
        else if(ft_strcmp(tree->op ,">") == 0)
        {
            fd_out = open(tree->branch2->cmd->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
            while((ft_strcmp(tree->branch1->op, ">") == 0 || ft_strcmp(tree->branch1->op, ">>") == 0 )&& tree->branch1->op != NULL )
            {
                tree = tree->branch1;
                fd_tmp = open(tree->branch2->cmd->name, O_RDWR | O_CREAT | O_TRUNC, 0777);
                close(fd_tmp);
            }
                if(ft_execution(tree->branch1, env, fd_out, in) == 3)
                    exit(0);
            }
        else if(ft_strcmp(tree->op ,">>") == 0)
        {
            fd_out = open(tree->branch2->cmd->name, O_RDWR | O_CREAT | O_APPEND, 0644);
            while((ft_strcmp(tree->branch1->op, ">") == 0 || ft_strcmp(tree->branch1->op, ">>") == 0 )&& tree->branch1->op != NULL )
            {
                tree = tree->branch1;
                fd_tmp = open(tree->branch2->cmd->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
                close(fd_tmp);
            }
            ft_execution(tree->branch1, env, fd_out, in);
        }
        else if(ft_strcmp(tree->op,"<") == 0)
        {
            fd_in = open(tree->branch2->cmd->name,O_RDONLY);
            while((ft_strcmp(tree->branch1->op, "<") == 0 || ft_strcmp(tree->branch1->op, "<<") == 0 ) && tree->branch1->op != NULL)
            {
                tree = tree->branch1;
            }
                tree_tmp = tree;
                while(tree_tmp != NULL && (ft_strcmp(tree_tmp->op, "<") == 0 || ft_strcmp(tree_tmp->op, "<<") == 0))
                {
                    if(ft_strcmp(tree_tmp->op, "<") == 0)
                    {
                        if(access(tree_tmp->branch2->cmd->name, F_OK) == -1)
                        {
                            printf("minishell : %s No such file or directory\n", tree_tmp->branch2->cmd->name);
                            exit(4);
                        }
                        tree_tmp = tree_tmp->previous;
                    }
                    else
                    {
                        fd_tmp2 = open("o", O_RDWR | O_CREAT | O_TRUNC , 0644);
                        read_from_here_doc(fd_tmp2, tree_tmp->branch2->cmd->name, env);
                        close(fd_tmp2);
                        tree_tmp = tree_tmp->previous;
                    }
                }
                if(in == 1)
                    ft_execution(tree->branch1, env, ou, fd_in);
                else
                    ft_execution(tree->branch1, env, ou, in);
        }
        else if(ft_strcmp(tree->op,"<<") == 0)
        {
            while((ft_strcmp(tree->branch1->op, "<<") == 0 || ft_strcmp(tree->branch1->op, "<") == 0) && tree->branch1->op != NULL)
                {
                    tree = tree->branch1;
                }
                tree_tmp = tree->branch1;
            while((ft_strcmp(tree_tmp->previous->op, "<<") == 0 || ft_strcmp(tree_tmp->previous->op, "<") == 0) &&
                 tree_tmp->previous->previous != NULL && (ft_strcmp(tree_tmp->previous->previous->op, "<<") == 0 || ft_strcmp(tree_tmp->previous->previous->op, "<") == 0))
            {
                if(ft_strcmp(tree_tmp->previous->op, "<<") == 0)
                {
                    fd_tmp2 = open("o", O_RDWR | O_CREAT | O_TRUNC , 0644);
                    read_from_here_doc(fd_tmp2, tree_tmp->previous->branch2->cmd->name, env);
                    close(fd_tmp2);
                    tree_tmp = tree_tmp->previous;
                }
                else
                {
                    tree_tmp = tree_tmp->previous;
                }
            }
            read_from_here_doc(p[1], tree_tmp->previous->branch2->cmd->name, env);
            close(p[1]);
            tree_tmp = tree->branch1;
            while((ft_strcmp(tree_tmp->previous->op, "<<") == 0 || ft_strcmp(tree_tmp->previous->op, "<") == 0) &&
                 tree_tmp->previous->previous != NULL && (ft_strcmp(tree_tmp->previous->previous->op, "<<") == 0 || ft_strcmp(tree_tmp->previous->previous->op, "<") == 0))
            {
                if(ft_strcmp(tree_tmp->previous->op, "<") == 0)
                {
                        if(access(tree_tmp->previous->branch2->cmd->name, F_OK) == -1)
                        {
                            printf("minishell : %s No such file or directory\n", tree_tmp->previous->branch2->cmd->name);
                            exit(4);
                        }
                    tree_tmp = tree_tmp->previous;
                }
                else
                {
                    tree_tmp = tree_tmp->previous;
                }
            }
            if(ft_execution(tree->branch1, env, ou, p[0]) == 3)
                return (1);
        }
    }
    else
        {
            if(exec_cmd(tree, env , ou , in) == 3)
				return (3);
        }
    return(1);
}