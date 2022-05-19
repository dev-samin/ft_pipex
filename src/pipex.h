/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:22:11 by samin             #+#    #+#             */
/*   Updated: 2021/06/23 13:57:18 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "pipex.h"

void	check_infile(char argc, char **argv);
void	check_cmd(char **cmd, char **cmd1_argv, char **cmd2_argv);
int		find_path(char **envp);
char	*get_path(char **envp, char *cmd);

void	parrents(int pipefd[2], char **argv, char *cmd, char **cmd2_argv);
void	child(int pipefd[2], char **argv, char *cmd, char **cmd1_argv);

int		redirection_in(char *file);
int		redirection_out(char *file);
void	connect_pipe(int *pipefd, int io);
void	free_array(char **array);
void	free_all(char **cmd1_argv, char **cmd2_argv, char **cmd);

#endif
