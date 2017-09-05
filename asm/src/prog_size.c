/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:33:36 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/20 16:33:36 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		prog_size(t_char *lst, t_label *lbl)
{
	t_label			*l;
	long long int	res;
	t_command		*c;

	res = 0;
	l = lbl;
	while (l && res < 100000)
	{
		c = l->command;
		while (c && res < 100000)
		{
			res = res + weight_command(c, lst);
			c = c->next;
		}
		l = l->next;
	}
	lst->size = res / 2;
	return (1);
}
