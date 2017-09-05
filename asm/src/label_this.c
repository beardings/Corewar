/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_this.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:24:07 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/08 17:24:08 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		label_this(char *line)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = line;
	while (tmp && *tmp && (*tmp == ' ' || *tmp == '\t'))
	{
		j++;
		tmp++;
	}
	while (tmp && *tmp && *tmp != ':' && *tmp != ' ' && *tmp != '\t')
	{
		i++;
		tmp++;
	}
	if (!tmp || (tmp && !*tmp))
		return (-1);
	if (*tmp == ':')
		return (correct_label_char(line + j, i) ? 1 : -1);
	return (0);
}
