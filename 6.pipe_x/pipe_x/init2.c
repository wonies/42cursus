#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}

void    file_init(int ac, char **av, t_pipe *pp)
{
	pp->infile = open(av[1], O_RDONLY);
	printf("infile : %d\n", pp->infile);
    pp->outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (pp->outfile < 0)
        error_msg("Failed to open out file\n");
    pp->child = ac - 3;
    pp->com = (t_pid *)ft_calloc(pp->child, sizeof(t_pid));
	pp->cmd = NULL;
	pp->fd_path = NULL;
	pp->str = NULL;
	pp->check = 0;
}
