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
            return(0);
        }
    }
    else
    {
        if (ou != 1)
            close(ou);
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
            ft_execution(tree->branch1, env , 1, 0);
            ft_execution(tree->branch2, env, 1, 0);
        }
        else if(ft_strcmp(tree->op, "||") == 0)
        {
            if(ft_execution(tree->branch1, env, 1 , 0) == 0)
                ft_execution(tree->branch2, env, 1 , 0);
        }
        else if(ft_strcmp(tree->op, "|") == 0)
        {
            ft_execution(tree->branch1, env , p[1],in);
            sleep();
            ft_execution(tree->branch2, env, ou , p[0]);
            close(p[1]);
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
            ft_execution(tree->branch1, env, fd_out, in);
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
            while(ft_strcmp(tree->branch1->op, "<") == 0 && tree->branch1->op != NULL)
            {
                tree = tree->branch1;
            }
            ft_execution(tree->branch1, env, ou, fd_in);
        }
        else if(ft_strcmp(tree->op,"<<") == 0)
        {
            while(ft_strcmp(tree->branch1->op, "<<") == 0 && tree->branch1->op != NULL)
                {
                    tree = tree->branch1;
                }
                tree_tmp = tree->branch1;
            while(ft_strcmp(tree_tmp->previous->op, "<<") == 0 && tree_tmp->previous->previous != NULL)
            {
                fd_tmp2 = open("o", O_RDWR | O_CREAT | O_TRUNC , 0644);
                read_from_here_doc(fd_tmp2, tree_tmp->previous->branch2->cmd->name, env);
                close(fd_tmp2);
                tree_tmp = tree_tmp->previous;
            }
            read_from_here_doc(p[1], tree_tmp->previous->branch2->cmd->name, env);
            close(p[1]);
            ft_execution(tree->branch1, env, ou, p[0]);
        }
    }
    else
        {
            if(tree->cmd->path == NULL)
            {
                printf("Minishell: %s: command not found\n",tree->cmd->name);
                return(0);
            }
            else
            {
                exec_cmd(tree, env , ou , in);
            }
        }
    return(1);
}