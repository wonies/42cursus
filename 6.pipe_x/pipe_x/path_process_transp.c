/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_process_transp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:08 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 16:35:57 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_transp_the_one(int zero, t_pipe *pp)
{
	if ((close(pp->com[zero].pipe_fd[0]) < 0) \
		|| (dup2(pp->infile, STDIN_FILENO) < 0) \
		|| (dup2(pp->com[zero].pipe_fd[1], STDOUT_FILENO) < 0) \
		|| (dup2(pp->com[zero].pipe_fd[0], STDIN_FILENO) < 0) \
		|| (dup2(pp->outfile, STDOUT_FILENO) < 0))
	{
		if (pp->infile < 0)
			exit(1);
		else
			error_msg("ONLY ONE ERROR!\n");
	}
}

void	process_check_zero(int i, t_pipe *pp)
{
	if ((close(pp->com[i].pipe_fd[0]) < 0) \
		|| (dup2(pp->infile, STDIN_FILENO) < 0) \
		|| (dup2(pp->com[i].pipe_fd[1], STDOUT_FILENO) < 0))
	{
		if (pp->infile < 0)
			exit(1);
		else
			error_msg("first child ERROR!\n");
	}
}

void	process_transp(int i, t_pipe *pp)
{
	if (i == 0)
		process_check_zero(i, pp);
	else if (i == pp->child - 1)
	{
		if ((dup2(pp->com[i - 1].pipe_fd[0], STDIN_FILENO) < 0) \
			|| (dup2(pp->outfile, STDOUT_FILENO) < 0))
			error_msg("last child ERROR!\n");
	}
	else
	{
		if ((close(pp->com[i].pipe_fd[0]) < 0) \
			|| (dup2(pp->com[i - 1].pipe_fd[0], STDIN_FILENO) < 0) \
			|| (dup2(pp->com[i].pipe_fd[1], STDOUT_FILENO) < 0))
			error_msg("mid child ERROR!\n");
	}
}
