/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:00:11 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 16:00:12 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*write_label_name(t_label *l, char *line)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (l->next)
		l = l->next;
	l->next = (t_label *)malloc(sizeof(t_label));
	l = l->next;
	function_for_first_time(&l);
	tmp = line;
	while (tmp && *tmp && (*tmp == ' ' || *tmp == '\t'))
	{
		j++;
		tmp++;
	}
	while (tmp && *tmp && *tmp != ':')
	{
		i++;
		tmp++;
	}
	l->name = ft_strndup(line + j, i);
	return (l);
}
