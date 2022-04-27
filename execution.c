#include "minishell.h"
extern int status;
int exec_cmd(t_tree *tree, char **env, int ou, int in)
{
    int pid = fork();
    if (pid == 0)
    {
        dup2(ou, 1);
        if (ou != 1)
            close(ou);
        dup2(in, 0);
        if (in != 0)
            close(in);
        if (execve(tree->cmd->path, ft_path_split(tree->cmd->name, ' '), env) == -1)
        {
            ft_putstr_fd("Minishell: ", 2);
            ft_putstr_fd(tree->cmd->name, 2);
            ft_putstr_fd(": command not found\n", 2);
            return(3);
        }
    }
    waitpid(pid, &status, 0);
    return (status);
}
void run_pipe(t_tree *tree, char **env ,int ou, int in)
{
    int p[2];

    pipe(p);
            if(fork() == 0)
            {
                close(p[0]);
                if (ft_execution(tree->branch1, env, p[1], in) == 3)
                    exit(1);
                close(p[1]);
                exit(0);
            }

            if(fork() == 0)
            {
                close(p[1]);
                if (ft_execution(tree->branch2, env, ou, p[0]) == 3)
                    exit(1);
                close(p[0]);
                exit(0);
            }
            close(p[0]);
            close(p[1]);
            waitpid(-1, &status, 0);
            waitpid(-1, &status, 0);

}
int ft_execution(t_tree *tree, char **env, int ou, int in)
{
    if (!tree)
        exit(5);
    if (tree->op != NULL)
    {
        if (ft_strcmp(tree->op, "&&") == 0 || ft_strcmp(tree->op, "||") == 0)
            run_and_or(tree, env, ou, in);
        else if (ft_strcmp(tree->op, "|") == 0)
            run_pipe(tree, env, ou, in);
        else if (ft_strcmp(tree->op, ">") == 0)
            run_redirect_output(tree, env ,in);
        else if (ft_strcmp(tree->op, ">>") == 0)
            run_redirect_output_append(tree, env, in);
        else if (ft_strcmp(tree->op, "<") == 0)
            run_redirect_input(tree, env ,  ou , in);
        else if (ft_strcmp(tree->op, "<<") == 0)
            run_here_doc(tree,env ,ou);
    }
    else
    {
        if (exec_cmd(tree, env, ou, in) == 3)
            return (3);
    }
    return (1);
}