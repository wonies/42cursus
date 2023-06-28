/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:20 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 16:35:15 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	isok_access(t_pipe *pp)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (pp->str[i])
	{
		temp = ft_strjoin(pp->str[i], pp->cmd[0]);
		if (access(temp, X_OK) == 0)
		{
			pp->fd_path = temp;
			break ;
		}
		free(temp);
		i++;
	}
	if (!pp->fd_path)
		error_msg("command not found\n");
}

void	make_slash(t_pipe *pp)
{
	int		i;
	char	*temp;

	i = 0;
	while (pp->str[i])
	{
		temp = ft_strjoin(pp->str[i], "/");
		free(pp->str[i]);
		pp->str[i] = temp;
		i++;
	}
}

char	*find_path(char **env)
{
	char	*path;

	path = NULL;
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break ;
		}
		env++;
	}
	return (path);
}

void	function_path(char **av, char **env, t_pipe *pp)
{
	pp->env = env;
	if (!pp->env)
		error_msg("not allocated ENV!\n");
	pp->path = find_path(env);
	if (!pp->path)
		error_msg("not allocated PATH!\n");
	pp->str = ft_split(pp->path, ':');
	if (!pp->str)
		error_msg("not allocated SPLIT!\n");
	make_slash(pp);
	if (!pp->str)
		error_msg("not allocated JOIN!\n");
	execute(pp, av);
}
