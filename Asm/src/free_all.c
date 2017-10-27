/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:01:18 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 13:01:18 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_c_param_i(t_command **c)
{
	if ((*c)->param[0])
		free((*c)->param[0]);
	if ((*c)->param[1])
		free((*c)->param[1]);
	if ((*c)->param[2])
		free((*c)->param[2]);
}

void	free_label(t_label *l)
{
	t_label		*s;
	t_command	*c;
	t_command	*d;

	s = l;
	while (s)
	{
		if (s->name)
			free(s->name);
		c = s->command;
		while (c)
		{
			free_c_param_i(&c);
			free(c->param);
			d = c;
			c = c->next;
			free(d);
		}
		l = s;
		s = s->next;
		free(l);
	}
}

void	free_char(t_char *lst)
{
	if (lst && lst->name)
		free(lst->name);
	if (lst && lst->comment)
		free(lst->comment);
	if (lst)
		free(lst);
}

void	free_all(t_char *lst, t_label *l, char *line)
{
	if (lst)
		free_char(lst);
	if (l)
		free_label(l);
	if (line)
		free(line);
}
