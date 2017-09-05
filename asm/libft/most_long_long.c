/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_long_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:20:10 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/11 17:20:10 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlongcmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 <= *s2++ && n--)
		if (*s1++ == '\0' || !n)
			return (0);
	s2--;
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void			str_go_num(char *str, int *ii, int *tt)
{
	int		t;
	int		i;

	i = *ii;
	t = *tt;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		t++;
		i++;
	}
	*ii = i;
	*tt = t;
}

long long int	most_long_long(char *str)
{
	int			i;
	int			minus;
	int			t;

	t = 0;
	i = 0;
	minus = 0;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	str_go_num(str, &i, &t);
	if (t < 19)
		return (ft_atoi(str));
	if (t > 19 && !minus)
		return (9223372036854775807);
	if (t > 19 && minus)
		return (0);
	if (!minus && (ft_strlongcmp(str, "9223372036854775807", t) > 0))
		return (9223372036854775807);
	if (minus && (ft_strlongcmp(str + 1, "9223372036854775807", t + minus) > 0))
		return (0);
	return (ft_atoi(str));
}
