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
    // int fd_in = 0;
    // int fd_tmp = 0;
    pipe(p);

    if(tree->op != NULL)
    {
        if(strcmp(tree->op,"&&") == 0)
        {
            ft_execution(tree->branch1, env , 1, 0);
            ft_execution(tree->branch2, env, 1, 0);
        }
        else if(strcmp(tree->op, "||") == 0)
        {
            if(ft_execution(tree->branch1, env, 1 , 0) == 0)
                ft_execution(tree->branch2, env, 1 , 0);
        }
        else if(strcmp(tree->op, "|") == 0)
        {
            ft_execution(tree->branch1, env , p[1],0);
            ft_execution(tree->branch2, env, ou , p[0]);
            close(p[1]);
            close(p[0]);
        }
        // else if(strcmp(tree->op,"<") == 0)
        // {
        //     if(strcmp(tree->branch1->op,"|") == 0)
        //     {
        //         fd_in = open(tree->branch2->cmd->name, O_WRONLY, O_TRUNC, 0777);
        //         ft_execution(tree->branch1->branch2, env, fd_out, in);
        //     }
        // }
        else if(strcmp(tree->op ,">") == 0)
        {
            fd_out = open(tree->branch2->cmd->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
            printf("fd : %d", fd_out);
            close(fd_out);
            exit(0);
                        // while(strcmp(tree->branch1->op, ">") == 0)
            // {
            //     tree = tree->branch1;
            //     fd_tmp = open(tree->branch2->cmd->name , O_WRONLY, O_TRUNC, 0777);
            //     close(fd_tmp);
            // }
            ft_execution(tree->branch1, env, fd_out, in);
        }
        // else if(strcmp(tree->op) == ">>")
        // {
            
        // }
        // else if(strcmp(tree->op) == ">>")
        // {

        // }
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