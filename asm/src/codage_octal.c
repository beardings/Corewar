/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codage_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:39:17 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/13 15:39:18 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			stepen_n(int i, int z)
{
	int		tmp;

	tmp = i;
	while (z > 1)
	{
		tmp = tmp * i;
		z--;
	}
	return (tmp);
}

char		*return_hex_octal(int i)
{
	int		tmp;
	int		j;

	j = 0;
	tmp = 0;
	while (i)
	{
		tmp = tmp + i % 10 * stepen_n(2, j);
		i = i / 10;
		j++;
	}
	return (ten_hex(tmp, NULL, 2));
}

char		*codage_octal(t_command *c, t_char *lst)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (lst->op[c->opcode - 1].octage)
	{
		while (j < c->num_param)
		{
			if (c->param_type[j] == 1)
				i = i == 0 ? 1 : i * 100 + 1;
			if (c->param_type[j] == 2 || c->param_type[j] == 20)
				i = i * 100 + 10;
			if (c->param_type[j] == 4 || c->param_type[j] == 40)
				i = i * 100 + 11;
			j++;
		}
		if (j == 2)
			i = i * 10000;
		if (j == 3)
			i = i * 100;
	}
	return (return_hex_octal(i));
}
