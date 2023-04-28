// #include "push_swap.h"

// int    ft_strlen(char *str)
// {
//     int i = 0;
//     while (str[i])
//         i++;
//     return i;
// }

// void    push_swap(char **psp, int i, int idx)
// {
//     char *res[10];
    
//     int len = ft_strlen(psp[i]);
//     res[idx] = psp[i];
//     printf("res : %d : %s\n", idx, res[idx]);
// }


// int main(int ac, char **av)
// {
//     int idx = 0;
//     for (int i=1; i<ac; i++)
//     {
//         push_swap(&av[i], i, idx);
//         idx++;
//     }
// // }
// #include "push_swap.h"

// int ft_strlen(char *str)
// {
//     int i = 0;
//     while (str[i])
//         i++;
//     return i;
// }

// void push_swap(char *psp, char *res, int i)
// {
//     int len = ft_strlen(psp);
//     for (int j = 0; j < len; j++)
//         res[j] = psp[j];
//     printf("res : %d : %s\n", i, res);
// }

// int main(int ac, char **av)
// {
//     char res[ac - 1][20]; // 입력되는 숫자의 개수만큼 배열 선언

//     for (int i = 1; i < ac; i++)
//     {
//         push_swap(av[i], res[i - 1], i - 1);
//     }
// }
