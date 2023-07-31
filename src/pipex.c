/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:32:55 by mrabat            #+#    #+#             */
/*   Updated: 2023/07/31 18:36:38 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{   

    pipex(argv[4], argv[2], argv[3],envp);
    if (argc < 5) 
    { 
        //ft_putstr_fd("ARGUMENTS ERROR !",2);
        return (1);
    }
    if (ft_arg_error(argv))
        return (1);
    
    return (0);
}


void pipex(char *filename, char *arg1, char *arg2, char **envp)
{
    t_pipex *mypipex;
    char    **path;

    mypipex = malloc(sizeof(t_pipex));
    mypipex->splitarg1 = ft_split(arg1, ' ');
    mypipex->splitarg2 = ft_split(arg2, ' ');
    path = ft_split(ft_getenvpath(envp), ':');

    ft_checkexe(mypipex->splitarg1[0], path);
    ft_checkexe(mypipex->splitarg2[0], path);
    if (pipe(mypipex->fd) == -1)
    {
        ft_printf("fail... \n");
        exit(EXIT_FAILURE);
    }

    mypipex->pid1 = fork();
    if (mypipex->pid1 < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (mypipex->pid1 == 0)
    {
        dup2(mypipex->fd[1], STDOUT_FILENO);
        close(mypipex->fd[0]);
        execve(ft_checkexe(mypipex->splitarg1[0], path), mypipex->splitarg1, envp);

    }
    mypipex->pid2 = fork();
    if (mypipex->pid2 < 0) 
    {
        exit(EXIT_FAILURE);
    }
    if (mypipex->pid2 == 0)
    {
        dup2(mypipex->fd[0],STDIN_FILENO);
        close(mypipex->fd[1]);
        ft_initfile(filename);
        execve(ft_checkexe(mypipex->splitarg2[0], path), mypipex->splitarg2, envp);

    }
    ft_closefd(mypipex->fd);
    waitpid(mypipex->pid1, NULL, 0);
    waitpid(mypipex->pid2, NULL, 0);
}