/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:18:57 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 16:18:57 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		cal1(t_label *start, t_command *c, t_char *lst, char *str)
{
	t_label		*s;
	t_command	*k;
	int			res;

	res = 0;
	s = start;
	while (s)
	{
		if (s->name && !ft_strcmp(s->name, str))
			break ;
		s = s->next;
	}
	while (s)
	{
		k = s->command;
		while (k && k->opcode != -1)
		{
			if (k == c)
				return (res);
			res = res + weight_command(k, lst);
			k = k->next;
		}
		s = s->next;
	}
	return (res);
}

int		cal2(t_label *now, t_command *c, t_char *lst)
{
	t_command	*k;
	int			res;

	res = 0;
	k = now->command;
	while (k && k != c)
	{
		if (k == c)
			return (res);
		res = res + weight_command(k, lst);
		k = k->next;
	}
	return (res);
}

int		cal3(t_label *now, t_command *c, t_char *lst, char *str)
{
	t_label		*s;
	t_command	*k;
	int			res;

	res = 0;
	s = now;
	k = c;
	while (s)
	{
		if (s->name && !ft_strcmp(s->name, str))
			return (res);
		while (k)
		{
			res = res + weight_command(k, lst);
			k = k->next;
		}
		s = s->next;
		if (s)
			k = s->command;
	}
	return (res);
}
