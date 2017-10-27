/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:22:20 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/21 20:22:21 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#define R1 0
#define R2 1
#define POS 2

void	sub(t_players *player, byte *map)
{
	int		r1;
	int		r2;

	if (check_oppcode(player, map) == 0)
		return ;
	r1 = get_REG(player, player->pos + 2, map);
	r2 = get_REG(player, player->pos + 3, map);
	player->reg[map[(player->pos + 4) % MEM_SIZE] - 1] = r1 - r2;
	player->pos += 5;
	if (r1 - r2 == 0)
		player->carry = 1;
	else
		player->carry = 0;
}

void	add(t_players *player, byte *map)
{
	int		r1;
	int		r2;

	if (check_oppcode(player, map) == 0)
		return ;
	r1 = get_REG(player, player->pos + 2, map);
	r2 = get_REG(player, player->pos + 3, map);
	player->reg[map[(player->pos + 4) % MEM_SIZE] - 1] = r1 + r2;
	player->pos += 5;
	if (r1 + r2 == 0)
		player->carry = 1;
	else
		player->carry = 0;
}

void	and_xor(t_players *player, byte *map, char flag)
{
	int		r1;
	int		r2;
	int		posit;
	char	*opp;
	int		*args[3];

	posit = 1;
	r1 = 0;
	r2 = 0;
	args[R1] = &r1;
	args[R2] = &r2;
	args[POS] = &posit;
	if (check_oppcode(player, map) == 0)
		return ;
	opp = get_binary(map, player);
	and_xor_part2(opp, player, map, args);
	and_xor_part3(opp, player, map, args);
	free(opp);
	if ((unsigned char)(map[((*player).pos + posit + 1)
			% MEM_SIZE] - 1) > REG_NUMBER - 1)
	{
		player->pos += posit + 2;
		return ;
	}
	and_xor_part4(flag, player, map, args);
}

void	and_xor_part2(char *opp, t_players *player, byte *map, int **args)
{
	opp = get_binary(map, player);
	if (ft_strnstr(opp, "01", 2))
	{
		*args[R1] = get_REG(player, player->pos + *args[POS] + 1, map);
		*args[POS] += 1;
	}
	else if (ft_strnstr(opp, "10", 2))
	{
		*args[R1] = get_TDIR(4, player->pos + *args[POS] + 1, map);
		*args[POS] += 4;
	}
	else if (ft_strnstr(opp, "11", 2))
	{
		*args[R1] = get_INDIR(player, 'r', player->pos + *args[POS] + 1, map);
		*args[POS] += 2;
	}
	opp += 2;
}

void	and_xor_part3(char *opp, t_players *player, byte *map, int **args)
{
	if (ft_strnstr(opp, "01", 2))
	{
		*args[R2] = get_REG(player, player->pos + *args[POS] + 1, map);
		*args[POS] += 1;
	}
	else if (ft_strnstr(opp, "10", 2))
	{
		*args[R2] = get_TDIR(4, player->pos + *args[POS] + 1, map);
		*args[POS] += 4;
	}
	else if (ft_strnstr(opp, "11", 2))
	{
		*args[R2] = get_INDIR(player, 'r', player->pos + *args[POS] + 1, map);
		*args[POS] += 2;
	}
	opp -= 2;
}

void	and_xor_part4(char flag, t_players *player, byte *map, int **args)
{
	if (flag == 'a')
		player->reg[map[((*player).pos + *args[POS] + 1)
			% MEM_SIZE] - 1] = *args[R1] & *args[R2];
	else if (flag == 'o')
		player->reg[map[((*player).pos + *args[POS] + 1)
			% MEM_SIZE] - 1] = *args[R1] | *args[R2];
	else if (flag == 'x')
		player->reg[map[((*player).pos + *args[POS] + 1)
			% MEM_SIZE] - 1] = *args[R1] ^ *args[R2];
	player->pos += *args[POS] + 2;
	if (flag == 'a' && (*args[R1] & *args[R2]) == 0)
		player->carry = 1;
	else if (flag == 'o' && (*args[R1] | *args[R2]) == 0)
		player->carry = 1;
	else if (flag == 'x' && (*args[R1] ^ *args[R2]) == 0)
		player->carry = 1;
	else
		player->carry = 0;
}
