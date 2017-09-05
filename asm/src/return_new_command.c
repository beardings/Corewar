/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_new_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:54:18 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 15:54:19 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		for_return_n_c(t_command **t)
{
	(*t)->next = NULL;
	(*t)->opcode = -1;
	(*t)->num_param = 0;
	(*t)->param_type[0] = 0;
	(*t)->param_type[1] = 0;
	(*t)->param_type[2] = 0;
	(*t)->param = (char **)malloc(sizeof(char *) * 3);
}

t_command	*return_new_command(t_label *l, t_command **t)
{
	t_command	*s;
	char		**tmp;

	if (*t == NULL)
	{
		while (l->next)
			l = l->next;
		s = l->command;
		while (s && s->next)
			s = s->next;
		*t = s;
	}
	if ((*t)->opcode == -1)
		return (*t);
	else
	{
		(*t)->next = (t_command *)malloc(sizeof(t_command));
		*t = (*t)->next;
		for_return_n_c(t);
		tmp = (*t)->param;
		tmp[0] = NULL;
		tmp[1] = NULL;
		tmp[2] = NULL;
	}
	return (*t);
}
