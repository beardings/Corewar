/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:12:11 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/21 20:12:13 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		aff(t_players *player, byte *map)
{
	int		reg;

	if (check_oppcode(player, map) == 0)
		return ;
	reg = get_REG(player, player->pos + 2, map);
	if (reg < 32 || reg > 127)
	{
		player->pos += 3;
		return ;
	}
	ft_putstr("Player #");
	ft_putnbr(player->num * -1);
	ft_putstr(" says: ");
	ft_putchar(reg);
	ft_putchar('\n');
	player->pos += 3;
}

void		fork_func(t_players *player, byte *map, t_players **stack)
{
	short int	dir;
	t_players	*tmp;

	dir = (short int)get_TDIR(2, player->pos + 1, map) % IDX_MOD;
	tmp = (t_players*)malloc(sizeof(t_players));
	*stack == NULL ? tmp->next = NULL : 0;
	tmp->next = *stack;
	*stack = tmp;
	ft_strncpy(tmp->header.prog_name, "fork", 4);
	tmp->comands = NULL;
	tmp->reg = (unsigned int*)malloc(sizeof(unsigned int) * REG_NUMBER);
	ft_memcpy(tmp->reg, player->reg, sizeof(unsigned int) * REG_NUMBER);
	tmp->live = player->live;
	tmp->live_amount = player->live_amount;
	tmp->cycles = player->cycles;
	tmp->num = player->num;
	tmp->last_herro = player->last_herro;
	tmp->st = -1;
	if (player->pos + dir < 0)
		dir = MEM_SIZE + dir;
	tmp->pos = (player->pos + dir) % MEM_SIZE;
	get_stop(tmp, map);
	tmp->carry = player->carry;
	tmp->number = player->number;
	player->pos += 3;
}

void	lfork_func(t_players *player, byte *map, t_players **stack)
{
	short int	dir;
	t_players	*tmp;

	dir = (short int)get_TDIR(2, player->pos + 1, map);
	dir + player->pos < 0 ? dir = player->pos : 0;
	tmp = (t_players*)malloc(sizeof(t_players));
	tmp->next = *stack;
	*stack = tmp;
	ft_strncpy(tmp->header.prog_name, "fork", 4);
	tmp->comands = NULL;
	tmp->reg = (unsigned int*)malloc(sizeof(unsigned int) * REG_NUMBER);
	ft_memcpy(tmp->reg, player->reg, sizeof(unsigned int) * REG_NUMBER);
	tmp->live = player->live;
	tmp->live_amount = player->live_amount;
	tmp->st = -1;
	if (player->pos + dir < 0)
		dir = MEM_SIZE + dir;
	tmp->pos = (player->pos + dir) % MEM_SIZE;
	get_stop(tmp, map);
	tmp->cycles = player->cycles;
	tmp->last_herro = player->last_herro;
	tmp->num = player->num;
	tmp->carry = player->carry;
	tmp->number = player->number;
	player->pos += 3;
}
