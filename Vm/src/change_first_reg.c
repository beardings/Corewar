/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_first_reg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:29:05 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 18:30:03 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void				ch_next(int *what, unsigned int *reg, t_players *tmp)
{
	if (tmp->num != -1)
	{
		tmp->reg = reg;
		tmp->reg[0] = tmp->num * -1;
	}
	else
	{
		tmp->reg = reg;
		tmp->reg[0] = *what * -1;
		tmp->num = *what;
		(*what)++;
	}
}

void				change_first_reg_players(t_players **players)
{
	t_players		*tmp;
	unsigned int	*reg;
	int				i;
	int				what;

	what = 1;
	tmp = *players;
	if (tmp->header.magic == 0)
		return ;
	while (tmp != NULL)
	{
		reg = (unsigned int *)malloc(sizeof(unsigned int) * 16);
		i = 0;
		while (i < 16)
		{
			reg[i] = 0;
			i++;
		}
		ch_next(&what, reg, tmp);
		tmp = tmp->next;
	}
}
