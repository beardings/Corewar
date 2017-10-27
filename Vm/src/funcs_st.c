/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:19:40 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/21 20:19:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	st(t_players *player, byte *map)
{
	int				r2;
	char			*binary;
	int				posit;
	unsigned int	r1;

	posit = 2;
	if (check_oppcode(player, map) == 0)
		return ;
	binary = get_binary(map, player);
	binary += 2;
	r2 = 0;
	if (ft_strnstr(binary, "11", 2))
	{
		r2 = (short int)get_indir(player, 'd', player->pos + posit + 1, map) % IDX_MOD;
		posit += 2;
	}
	else if (ft_strnstr(binary, "01", 2))
	{
		r2 = get_reg(player, player->pos + posit + 1, map) % IDX_MOD;
		posit++;
	}
	binary -= 2;
	free(binary);
	if (player->pos + r2 < 0)
		r2 = MEM_SIZE + r2;
	r1 = (unsigned int)get_reg(player, player->pos + 2, map);
	map[(player->pos + r2) % MEM_SIZE] = r1 / 0x1000000;
	map[(player->pos + r2 + 1) % MEM_SIZE] = (r1 / 0x10000) & 0xFF;
	map[(player->pos + r2 + 2) % MEM_SIZE] = (r1 / 0x100) & 0xFF;
	map[(player->pos + r2 + 3) % MEM_SIZE] = r1 % 0x100;
	player->st = (player->pos + r2) % MEM_SIZE;
	player->pos += posit + 1;
}

void	sti(t_players *player, byte *map)
{
	char				*binary;
	int					r1;
	int					r2;
	int					posit;
	unsigned int		r3;

	if (check_oppcode(player, map) == 0)
		return ;
	binary = get_binary(map, player);
	binary += 2;
	posit = 2;
	r1 = 0;
	r2 = 0;
	if (ft_strnstr(binary, "01", 2))
	{
		r1 = get_reg(player, player->pos + posit + 1, map);
		posit++;
	}
	else if (ft_strnstr(binary, "10", 2))
	{
		r1 = get_tdir(2, player->pos + posit + 1, map);
		posit += 2;
	}
	else if (ft_strnstr(binary, "11", 2))
	{
		r1 = get_indir(player, 'r', player->pos + posit + 1, map);
		posit += 2;
	}
	binary += 2;
	if (ft_strnstr(binary, "01", 2))
	{
		r2 = get_reg(player, player->pos + posit + 1, map);
		posit++;
	}
	else if (ft_strnstr(binary, "10", 2))
	{
		r2 = get_tdir(2, player->pos + posit + 1, map);
		posit += 2;
	}
	binary -= 4;
	free(binary);
	r3 = (unsigned int)get_reg(player, player->pos + 2, map);
	if (player->pos + ((r1 + r2) % IDX_MOD) < 0)
	{
		map[(MEM_SIZE + (player->pos + ((r1 + r2) % IDX_MOD))) % MEM_SIZE] = r3 / 0x1000000;
		map[(MEM_SIZE + (player->pos + ((r1 + r2) % IDX_MOD + 1))) % MEM_SIZE] = (r3 / 0x10000) & 0xFF;
		map[(MEM_SIZE + (player->pos + ((r1 + r2) % IDX_MOD + 2))) % MEM_SIZE] = (r3 / 0x100) & 0xFF;
		map[(MEM_SIZE + (player->pos + ((r1 + r2) % IDX_MOD + 3))) % MEM_SIZE] = r3 % 0x100;
		player->st = (MEM_SIZE + (player->pos + ((r1 + r2) % IDX_MOD))) % MEM_SIZE;
	}
	else
	{
		map[(player->pos + ((r1 + r2) % IDX_MOD)) % MEM_SIZE] = r3 / 0x1000000;
		map[(player->pos + ((r1 + r2) % IDX_MOD + 1)) % MEM_SIZE] = (r3 / 0x10000) & 0xFF;
		map[(player->pos + ((r1 + r2) % IDX_MOD + 2)) % MEM_SIZE] = (r3 / 0x100) & 0xFF;
		map[(player->pos + ((r1 + r2) % IDX_MOD + 3)) % MEM_SIZE] = r3 % 0x100;
		player->st = (player->pos + ((r1 + r2) % IDX_MOD)) % MEM_SIZE;
	}
	player->pos += posit + 1;
}
