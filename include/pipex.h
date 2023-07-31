/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:57:43 by mrabat            #+#    #+#             */
/*   Updated: 2023/07/31 15:46:48 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
#include "../lib/libft/libft.h"

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipex
{
	int		pid1;
	int		pid2;
	int		pidnum;
	char	**arg;
	char	*filename;
	int		fd[2];
    char **splitarg1;
    char **splitarg2;
}				t_pipex;

int ft_arg_error(char **argv);
int ft_check_file_exist(char *fd);
void    ft_initfile(char *filename);
void    pipex(char *filename, char *arg1, char *arg2, char **envp);
char    *ft_getcmd(char *arg);
char    *ft_getenvpath(char **envp);
void    ft_closefd(int *fd);
char    *ft_checkexe(char *for_exe, char **envp);
#endif