/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:13:58 by wonhshin          #+#    #+#             */
/*   Updated: 2023/06/28 16:38:40 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_gnl(t_pipe *pp)
{
	char	*str;

	str = get_next_line(0);
	if (!str)
		return ;
	if (strncmp(str, pp->limiter, pp->limiter_len) == 0)
	{
		free(str);
		return ;
	}
	while (str)
	{
		if (strncmp(str, pp->limiter, pp->limiter_len) == 0)
		{
			free(str);
			break ;
		}
		write(pp->infile, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	close(pp->infile);
	pp->infile = open(HEREDOC, O_RDONLY);
}

void	fileinit_bonus(int ac, char **av, t_pipe *pp)
{
	pp->infile = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	infile_errmsg(pp, av);
	pp->limiter = av[2];
	if (!pp->limiter)
		error_msg("syntax error near unexpected token `newline'\n");
	pp->limiter_len = ft_strlen(pp->limiter);
	pp->check = 114;
	if (ac > 3)
	{
		pp->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (pp->outfile < 0)
			error_msg("CANT OPEN OUTFILE\n");
	}
	if (ac == 3 || ac == 4)
	{
		read_gnl(pp);
		return ;
	}
	pp_setting(ac, pp);
}
