/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:18:46 by samin             #+#    #+#             */
/*   Updated: 2021/06/23 09:30:56 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		redirection_in(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int		redirection_out(char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_TRUNC);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

void	connect_pipe(int *pipefd, int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(char **cmd1_argv, char **cmd2_argv, char **cmd)
{
	free_array(cmd1_argv);
	free_array(cmd2_argv);
	free(cmd[0]);
	free(cmd[1]);
}
