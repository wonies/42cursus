#include "../includes/minishell.h"

t_list	*ft_lstnews()
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	return (new);
}


void	env_init(t_data *data, char **env)
{
	t_list	*new;
	int		i;

	i = -1;
	while (env[++i])
	{
		new = ft_lstnews();
		new->env = ft_strdup(env[i]);
		ft_lstadd_back(&data->envs, new);
	}
}

void    get_envp(t_data *data)
{
    t_list  *tmp;
    char    **str;
    int     size;
    int     i;
    
    i = -1;
    size = ft_lstsize(data->envs);
    str = (char **)ft_calloc(size, sizeof(char *));
    tmp = data->envs;
    while (++i < size)
    {
        str[i] = tmp->env;
        tmp = tmp->next;
    }
}

// void   del_envp(t_data *data, char *key)
// {
//     t_list *tmp;

//     tmp = find_envp(data, key);
    
//     //tmp->pre->next = tmp->next;
// }
// void    del_envp(t_data *data, char *key)
// {
//     t_list *tmp = find_envp(data, key);

//     if (tmp == NULL)
//         return ; 
//     if (tmp == data->envs)
//     {
//         data->envs = tmp->next; 
//         if (data->envs)
//             data->envs->pre = NULL; 
//     }
//     else
//     {
//         tmp->pre->next = tmp->next;  
//         if (tmp->next)
//             tmp->next->pre = tmp->pre; 
//     }
//     // free(tmp->env);  
//     // free(tmp);
// } // unset part --> 아니왜안되는거임 개킹받네


char    *find_envp(t_data *data, char *key)
{
    t_list *tmp;

    tmp = data->envs;
    while (tmp)
    {
        if (ft_strncmp(tmp->env, key, ft_strlen(key)) == 0)
            return (tmp->env);
        tmp = tmp->next;
    }
    return (NULL);
}


// void    init_env(char **env, t_list **head)
// {
//     int size;

//     size = ft_lstsize(*head);
//     envp->env = (char **)malloc((size + 1) * sizeof(char *));
//     if (!envp->env)
//         return ; 
// }

// void    insert_env(t_list **head, t_list *envp)
// {
//     t_list  *temp;

//     temp = *head;
//     init_env(&head);
    
//     int i;

//     i = 0;
//     while (temp)
//     {
//         envp-> 
//     }
// }