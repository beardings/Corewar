/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:31:25 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/10 18:31:25 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		find_label_in_label(char *str, t_label *lbl)
{
	t_label		*l;

	l = lbl->next;
	while (l)
	{
		if (l->name && !ft_strcmp(str, l->name))
			return (1);
		l = l->next;
	}
	return (0);
}

int		valid_label(t_label *l)
{
	t_command	*c;
	t_label		*tmp;

	tmp = l;
	while (tmp)
	{
		c = tmp->command;
		while (c && c->opcode != -1)
		{
			if (c->param_type[0] == 20 || c->param_type[0] == 40)
				if (!find_label_in_label(c->param[0], l))
					return (0);
			if (c->param_type[1] == 20 || c->param_type[1] == 40)
				if (!find_label_in_label(c->param[1], l))
					return (0);
			if (c->param_type[2] == 20 || c->param_type[2] == 40)
				if (!find_label_in_label(c->param[2], l))
					return (0);
			c = c->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
