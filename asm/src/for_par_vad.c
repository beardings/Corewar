/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_par_vad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:49:16 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 17:49:16 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*delete_fuck(char **ls)
{
	char	*res;
	char	*l;
	int		k;

	l = *ls;
	k = 0;
	while (*l && (*l == ' ' || *l == '\t'))
	{
		k++;
		l++;
	}
	res = *ls;
	while (*res && *(res + 1))
		res++;
	while (*res && (*res == ' ' || *res == '\t'))
		res--;
	while (res != l)
	{
		res--;
		k++;
	}
	k++;
	res = ft_strndup(*ls, k);
	free(*ls);
	return (res);
}

char		**ft_array_trim(char **array)
{
	char	**res;
	int		i;
	int		j;

	j = array_len(array);
	i = -1;
	res = (char**)malloc(sizeof(char*) * (j + 1));
	while (array[++i])
		res[i] = ft_strtrim(array[i]);
	res[i] = NULL;
	ft_freearray(array);
	return (res);
}

long int	array_len(char **arr)
{
	long int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}
