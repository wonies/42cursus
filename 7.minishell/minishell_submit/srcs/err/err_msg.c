/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:28:11 by wonhshin          #+#    #+#             */
/*   Updated: 2023/08/17 18:34:11 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	err_msg(char *msg)
{
	perror(msg);
	exit(errno);
}

void	syntax_err(char *msg)
{
	printf("%s\n", msg);
	exit(2);
}

void	print_exit(void)
{
	printf("exit\n");
	exit(1);
}

t_bool	error_code_read(char *str, int code, int flag)
{
	if (flag)
		perror(str);
	else
		printf("%s\n", str);
	g_exit_status = code;
	return (0);
}
