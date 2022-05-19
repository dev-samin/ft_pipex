/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samin <samin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:18:48 by samin             #+#    #+#             */
/*   Updated: 2021/06/23 09:35:44 by samin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc_argv(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_putstr_fd("not engough input value ", 1);
		exit(0);
	}
	if (access(argv[1], F_OK))
	{
		ft_putstr_fd("no such file or directory: ", 1);
		ft_putstr_fd(argv[1], 1);
		exit(0);
	}
	if (access(argv[4], F_OK))
	{
		ft_putstr_fd("no such file or directory: ", 1);
		ft_putstr_fd(argv[4], 1);
		exit(0);
	}
}

void	check_cmd(char **cmd, char **cmd1_argv, char **cmd2_argv)
{
	if (cmd[0] == NULL)
	{
		ft_putstr_fd("command not found: ", 1);
		ft_putstr_fd(cmd1_argv[0], 1);
		free_all(cmd1_argv, cmd2_argv, cmd);
		exit(0);
	}
	if (cmd[1] == NULL)
	{
		ft_putstr_fd("command not found: ", 1);
		ft_putstr_fd(cmd2_argv[0], 1);
		free_all(cmd1_argv, cmd2_argv, cmd);
		exit(0);
	}
}

int		find_path(char **envp)
{
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (i);
}

char	*get_path(char **envp, char *cmd)
{
	char	**envp_path;
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	envp_path = ft_split(envp[find_path(envp)] + 5, ':');
	while (envp_path[++i])
	{
		tmp = ft_strjoin(envp_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == -1)
		{
			free(path);
			path = NULL;
		}
		else
			break ;
		free(envp_path[i]);
	}
	while (envp_path[i])
		free(envp_path[i++]);
	free(envp_path);
	return (path);
}
