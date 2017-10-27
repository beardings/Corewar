/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_middle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:26:07 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 23:27:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_byte	*get_map(t_players *players, int count, int *cycles)
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
		{
			ptr = players[j].comands;
			players[j].cycles = cycles;
			j++;
		}
		get_map_dop(map, &ptr, i);
		i++;
	}
	return (map);
}

void	get_command2(t_players *player, t_byte *map, t_players **stack)
{
	if (player->curr_com == 6)
		and_xor(player, map, 'a');
	else if (player->curr_com == 7)
		and_xor(player, map, 'o');
	else if (player->curr_com == 8)
		and_xor(player, map, 'x');
	else if (player->curr_com == 9)
		zjmp(player, map);
	else if (player->curr_com == 10)
		ldi(player, map);
	else if (player->curr_com == 11)
		sti(player, map);
	else if (player->curr_com == 12)
		fork_func(player, map, stack);
	else if (player->curr_com == 13)
		lld(player, map);
	else if (player->curr_com == 14)
		lldi(player, map);
	else if (player->curr_com == 15)
		lfork_func(player, map, stack);
	else if (player->curr_com == 16)
		aff(player, map);
	else
		player->pos += 1;
}

void	get_command(t_players *player, t_byte *map, t_players **stack,
					t_players *players)
{
	if (player->stop == 0)
	{
		if (player->curr_com == 1)
			live(players, map, player);
		else if (player->curr_com == 2)
			ld(player, map);
		else if (player->curr_com == 3)
			st(player, map);
		else if (player->curr_com == 4)
			add(player, map);
		else if (player->curr_com == 5)
			sub(player, map);
		else
			get_command2(player, map, stack);
		player->pos = player->pos % MEM_SIZE;
		get_stop(player, map);
	}
	else
		player->stop -= 1;
}

int		get_alive_players(t_players *players)
{
	int			res;
	int			i;
	t_players	*tmp;

	res = 0;
	i = 0;
	tmp = players;
	while (tmp[i].header.prog_name[0] != '\0')
	{
		if (tmp[i].comands != NULL)
			res++;
		i++;
	}
	return (res);
}

int		get_last(t_players *players)
{
	int			i;
	int			res;

	i = 0;
	res = i;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (*(players[i].last_herro) == players[i].num)
			res = i;
		if (players[i].comands != NULL)
			free(players[i].comands);
		i++;
	}
	return (res);
}
