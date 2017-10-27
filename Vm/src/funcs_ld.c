/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:17:07 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/21 20:17:08 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	ld(t_players *player, byte *map)
{
	char	*binary;
	int		r1;
	int		posit;

	r1 = 0;
	posit = 1;
	if (check_oppcode(player, map) == 0)
		return ;
	binary = get_binary(map, player);
	if (ft_strnstr(binary, "10", 2))
	{
		r1 = get_TDIR(4, player->pos + posit + 1, map);
		posit += 4;
	}
	else if (ft_strnstr(binary, "11", 2))
	{
		r1 = get_INDIR(player, 'r', player->pos + posit + 1, map);
		posit += 2;
	}
	free(binary);
	for_ld_end(map, &player, posit, r1);
}

void	ldi(t_players *player, byte *map)
{
	int		r1;
	int		r2;
	int		for_r;
	int		posit;
	char	*binary;

	mu_obnylyaem(&r1, &r2, &for_r, &posit);
	if (check_oppcode(player, map) == 0)
		return ;
	binary = get_binary(map, player);
	for_r = for_ldi_peredstart(&player, &posit, map, &binary);
	r1 = for_r == -134 ? r1 : for_r;
	for_r = for_ldi_start(&player, &posit, map, &binary);
	r2 = for_r == -134 ? r2 : for_r;
	free(binary);
	if (return_ldi(map, player, &posit))
		return ;
	if (player->pos + r1 + r2 < 0)
		player->reg[map[player->pos + posit + 1] - 1] = get_TDIR(\
		4, MEM_SIZE + player->pos + ((r1 + r2) % IDX_MOD), map);
	else
		player->reg[map[player->pos + posit + 1] - 1] = get_TDIR(\
			4, player->pos + ((r1 + r2) % IDX_MOD), map);
	player->pos += posit + 2;
}

int		lldi_mf_norm(t_players **player, int *posit, byte *map, char **binary)
{
	int r1;

	r1 = -134;
	if (ft_strnstr((*binary), "01", 2))
	{
		r1 = get_REG((*player), (*player)->pos + (*posit) + 1, map);
		(*posit)++;
	}
	else if (ft_strnstr((*binary), "10", 2))
	{
		r1 = get_TDIR(2, (*player)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	else if (ft_strnstr((*binary), "11", 2))
	{
		r1 = get_INDIR((*player), 'r', (*player)->pos + (*posit) + 1, map);
		(*posit) += 2;
	}
	(*binary) += 2;
	return (r1);
}

void	lldi(t_players *player, byte *map)
{
	int		r1;
	int		r2;
	int		for_r;
	int		posit;
	char	*binary;

	mu_obnylyaem(&r1, &r2, &for_r, &posit);
	binary = get_binary(map, player);
	for_r = lldi_mf_norm(&player, &posit, map, &binary);
	r1 = for_r == -134 ? r1 : for_r;
	for_r = lldi_hahamf_norm(&player, &posit, map, &binary);
	r2 = for_r == -134 ? r2 : for_r;
	free(binary);
	if (map[(player->pos + posit + 1) % MEM_SIZE] < 1 \
		|| map[(player->pos + posit + 1) % MEM_SIZE] > REG_NUMBER)
	{
		player->pos += posit + 2;
		return ;
	}
	player->reg[map[player->pos + posit + 1] - 1] = get_TDIR(\
		4, (player->pos + r1 + r2) % MEM_SIZE, map);
	player->pos += posit + 2;
	player->carry = get_TDIR(4, (player->pos \
		+ r1 + r2) % MEM_SIZE, map) == 0 ? 1 : 0;
}

void	lld(t_players *player, byte *map)
{
	char	*binary;
	int		r1;
	int		posit;

	binary = for_blyalld(&r1, &posit, player, map);
	if (ft_strnstr(binary, "10", 2))
	{
		r1 = get_TDIR(4, player->pos + posit + 1, map);
		posit += 4;
	}
	else if (ft_strnstr(binary, "11", 2))
	{
		r1 = get_INDIR(player, 'r', player->pos + posit + 1, map);
		posit += 2;
	}
	free(binary);
	if (map[(player->pos + posit + 1) % MEM_SIZE] < 1 \
			|| map[(player->pos + posit + 1) % MEM_SIZE] > REG_NUMBER)
	{
		player->pos += ++posit + 1;
		return ;
	}
	player->reg[map[player->pos + posit + 1] - 1] = r1;
	player->pos += ++posit + 1;
	player->carry = r1 == 0 ? 1 : 0;
}
