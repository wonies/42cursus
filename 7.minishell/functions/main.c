#include "minifunction.h"

char    *ft_substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}


t_list  *createlist()
{
    return NULL;
}

void    addstringtolist(t_list **head, const char *str)
{
    t_list *new = (t_list *)malloc(sizeof(t_list));
    new->string = strdup(str);
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else
    {
        t_list *cur = *head;
        while (cur->next)
            cur = cur->next;
        cur->next = new;
    }
}


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    t_mini  minsh;
    t_list  *list = createlist();

    int idx = 0;
    int i = 0;
    char *str;
    str = "ls -al < a | grep "" ";
    while(str[idx])
    {
        if (str[idx] == ' ' || str[idx] == '\"' ||  str[idx] == '\'' || str[idx] == '|' || str[idx] == '<' || str[idx] == '>' )
        {
            // if (str[idx] == '\"')
                
            
            
            if (i != idx)
                addstringtolist(&list, ft_substr(str, i, idx));
            i = idx + 1;  
        }
        idx++;
    }

    t_list *current = list;
    while (current)
    {
        printf("%s\n", current->string);
        current = current->next;
    }
    current = list;
    while (current)
    {
        /* code */
        t_list *temp = current;
        current = current->next;
    }
    return 0;
}
