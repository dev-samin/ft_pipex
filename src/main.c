/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:27:18 by samin             #+#    #+#             */
/*   Updated: 2021/06/23 13:49:51 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parrents(int pipefd[2], char **argv, char *cmd, char **cmd2_argv)
{
	int status;

	redirection_out(argv[4]);
	wait(&status);
	connect_pipe(pipefd, STDIN_FILENO);
	execve(cmd, cmd2_argv, 0);
}

void	child(int pipefd[2], char **argv, char *cmd, char **cmd1_argv)
{
	connect_pipe(pipefd, STDOUT_FILENO);
	redirection_in(argv[1]);
	execve(cmd, cmd1_argv, 0);
}

int		main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmd1_argv;
	char	**cmd2_argv;
	char	*cmd[2];
	int		pipefd[2];

	check_infile(argc, argv);
	cmd1_argv = ft_split(argv[2], ' ');
	cmd2_argv = ft_split(argv[3], ' ');
	cmd[0] = get_path(envp, cmd1_argv[0]);
	cmd[1] = get_path(envp, cmd2_argv[0]);
	check_cmd(cmd, cmd1_argv, cmd2_argv);
	pipe(pipefd);
	pid = fork();
	if (pid > 0)
		parrents(pipefd, argv, cmd[1], cmd2_argv);
	else if (pid == 0)
		child(pipefd, argv, cmd[0], cmd1_argv);
	free_all(cmd1_argv, cmd2_argv, cmd);
	return (0);
}
