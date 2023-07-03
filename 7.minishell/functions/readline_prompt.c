#include "minifunction.h"

// void	handler(int sig)
// {
// 	if (sig != SIGINT)
// 		return ;
// 	printf(" ctrl + c\n");
// 	rl_on_new_line();
// 	// rl_replace_line("", 1);
// 	rl_redisplay();
// }

int main(void)
{
	int	res;
	char *line;

	// signal(SIGINT, handler);
	while (1)
	{
		line = readline("bash-3.2$ ");
		if (line)
		{
			if (strcmp(line, "exit") == 0)
			{
				printf("exit\n");
				break ;
			}
			printf("bash: %s: command not found \n", line);
			add_history(line);
			free(line);
			line = NULL;
		}
		else if (line == (void *)0)
		{
			printf("exit\n");
			break ;
		}
	}
	return 0;
}
