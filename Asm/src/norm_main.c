/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 17:31:50 by ngulya            #+#    #+#             */
/*   Updated: 2017/10/08 17:31:51 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		correct_end_s(char *s)
{
	while (*s && *(s + 1) && *(s + 2))
		s++;
	if (*s && !ft_strcmp(s, ".s"))
		return (1);
	return (0);
}

int		go_to_znak(char **line, int j)
{
	while (**line && **line != '"')
	{
		(*line)++;
		j++;
	}
	return (j);
}
