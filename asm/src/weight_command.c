/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:04:32 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/13 16:04:33 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		weight_command(t_command *c, t_char *lst)
{
	int		i;
	int		res;

	res = 2;
	i = 0;
	if (c->opcode == -1)
		return (0);
	if (lst->op[c->opcode - 1].octage)
		res = res + 2;
	while (i < c->num_param)
	{
		if (c->param_type[i] == 1)
			res = res + 2;
		if (c->param_type[i] == 2 || c->param_type[i] == 20)
			res = res + (lst->op[c->opcode - 1].label_size\
			? lst->op[c->opcode - 1].label_size * 2 : 4);
		if (c->param_type[i] == 4 || c->param_type[i] == 40)
			res = res + 4;
		i++;
	}
	return (res);
}
