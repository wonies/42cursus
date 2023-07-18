#include "../includes/minishell.h"

void	syntax_err(char *msg)
{
	printf("%s\n", msg);
	exit(2);
}