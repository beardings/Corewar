/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:48:02 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 19:33:41 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void				get_n(int *j, int *cycles, t_players *players, char **ptr)
{
	*ptr = players[*j].comands;
	players[*j].cycles = cycles;
	(*j)++;
}

byte				*get_map_color(t_players *players, int count, int *cycles)
{
	unsigned char	*map;
	int				i;
	int				j;
	char			*ptr;

	j = 1;
	i = 0;
	map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	ptr = players[0].comands;
	players[0].cycles = cycles;
	while (i < MEM_SIZE && j <= count)
	{
		if (i >= (MEM_SIZE / count) * j)
			get_n(&j, cycles, players, &ptr);
		if (ptr != NULL && *ptr != '\0')
		{
			map[i] = j;
			ptr += 2;
		}
		else
			map[i] = 0;
		i++;
	}
	return (map);
}

int					find_i(int *i, int *did, int skiko, int all)
{
	double			res;

	res = 0;
	while (*i < 4)
	{
		if (did[*i] > 0)
			break ;
		(*i)++;
	}
	res = all - did[*i];
	if (did[*i] > res)
	{
		res = ((double)did[*i] / (double)all) * 100;
		skiko = skiko * (res / 100);
	}
	else if (did[*i] < res)
	{
		res = ((double)did[*i] / (double)all) * 100;
		skiko = skiko * (res / 100);
	}
	else
		skiko = skiko / 2;
	return (skiko);
}

void				fill_pl_number(t_players *players)
{
	int				i;

	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		players[i].number = i + 1;
		i++;
	}
}

void				start_vm(t_players **tmp, int count, t_flags *flags)
{
	t_players		players[count + 1];
	int				i;
	t_players		*tmp1;

	i = 0;
	while (*tmp)
	{
		players[i] = **tmp;
		players[i].num *= -1;
		players[i].pos = 0 + (i * (MEM_SIZE / count));
		players[i].reg[0] = players[i].num;
		players[i].last_herro = &(flags->base);
		tmp1 = (*tmp)->next;
		free(*tmp);
		tmp = &tmp1;
		i++;
	}
	players[count].header.prog_name[0] = '\0';
	players[count].comands = NULL;
	tmp = NULL;
	fill_pl_number(players);
	if (flags->visual == 1)
		go_vm_vis(players, count, flags);
	else
		go_vm(players, count, flags);
}
