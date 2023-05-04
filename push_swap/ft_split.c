#include "push_swap.h"

size_t	count_str(char const *s, char c)
{
	int	flag;
	int	cnt;

	flag = 1;
	cnt = 0;
	while (*s)
	{
		if (flag == 1 && *s != c)
		{
			flag = 0;
			cnt++;
		}
		if (flag == 0 && *s == c)
			flag = 1;
		s++;
	}
	return (cnt);
}

char	**ft_free_split(char **str, int order)
{
	while (order >= 0)
	{
		free(str[order]);
		order--;
	}
	free(str);
	return (0);
}

size_t	str_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*put_word(char const *s, char c)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = str_len(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	index;

	index = 0;
	string = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!string)
		return (0);
	if (count_str(s, c) == 0)
	{
		string[0] = ft_strdup("");
		return string;
	}
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			string[index] = put_word(s, c);
			if (!string[index])
				return (ft_free_split(string, index - 1));
			index++;
		}
		while (*s && *s != c)
			s++;
	}
	string[index] = 0;
	return (string);
}
