/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_char_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:06:27 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 13:06:28 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		correct_label_char(char *str, int size)
{
	int		i;
	int		j;

	j = 0;
	while (*str && *str != ':' && size > 0)
	{
		i = 0;
		while (i < 37)
		{
			if (*str == LABEL_CHARS[i])
				break ;
			i++;
		}
		if (i == 37)
			return (0);
		str++;
		j++;
		size--;
	}
	if (!*str)
		return (0);
	return (j);
}

char	*return_after_spac_tab_str(char *str)
{
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	return (str);
}

int		correct_char_name(char *str, int size)
{
	int		j;

	j = 0;
	str = return_after_spac_tab_str(str);
	if (*str != '"')
		return (0);
	else
		str++;
	while (*str && *str != '"' && j < size + 2)
	{
		str++;
		j++;
	}
	if (*str != '"' || j > size || (j == 0 && size == 128))
		return (0);
	str++;
	while (*str)
	{
		if (*str == '#')
			return (1);
		if (*str && *str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}
