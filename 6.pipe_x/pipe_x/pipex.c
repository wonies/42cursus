/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:28 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 15:36:10 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipe	pp;

	if (ac != 5)
		error_msg("---We must write 4 arguments in the mandatory part---\n");
	file_init(ac, av, &pp);
	function_path(av, env, &pp);
	free_all(&pp);
	return (0);
}
