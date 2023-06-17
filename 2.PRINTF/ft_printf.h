/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:40:14 by wonhshin          #+#    #+#             */
/*   Updated: 2023/03/15 20:52:21 by wonhshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check(va_list ap, char c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putdeci(int str);
void	ft_str(char *s);
int		ft_putunsigned(unsigned int ui);
size_t	ft_putmemo(size_t mem);
int		ft_lowhex(unsigned int hex);
int		ft_uphex(unsigned int hex);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		itoa_len(long n);
char	*ft_itoa(int n);
char	*ft_unsignitoa(unsigned int n);
int		ft_memlen(size_t n);
char	*ft_memitoa(size_t n);
int		ft_hexlen(unsigned int n);
char	*ft_upitoa(unsigned int n);
char	*ft_lowitoa(unsigned int n);

#endif
