/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:56 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 16:38:06 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe	pp;

	if (strncmp(av[1], "here_doc", 9) == 0)
	{
		fileinit_bonus(ac, av, &pp);
		if (ac == 3 || ac == 4)
		{
			unlink(HEREDOC);
			return (0);
		}
		read_gnl(&pp);
	}
	else
		file_init(ac, av, &pp);
	function_path(av, env, &pp);
	free_all(&pp);
	return (0);
}
