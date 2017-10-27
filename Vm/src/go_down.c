/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:55:11 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/28 00:59:03 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	check_carry(t_players *player, int r1, int r2, char flag)
{
	if (flag == 'a' && (r1 & r2) == 0)
		player->carry = 1;
	else if (flag == 'o' && (r1 | r2) == 0)
		player->carry = 1;
	else if (flag == 'x' && (r1 ^ r2) == 0)
		player->carry = 1;
	else
		player->carry = 0;
}

void	stack_iter(t_players **tmp, t_players **tmp2)
{
	(*tmp)->live = 0;
	(*tmp)->live_amount = 0;
	*tmp2 = *tmp;
	*tmp = (*tmp)->next;
}

void	check_dead_proccess(t_players **stack)
{
	t_players	*tmp;
	t_players	*tmp2;

	tmp = *stack;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->live + tmp->live_amount == 0)
		{
			if (tmp2 == NULL)
				*stack = tmp->next;
			else
				tmp2->next = tmp->next;
			free(tmp->reg);
			tmp->reg = NULL;
			free(tmp);
			if (tmp2 == NULL)
				tmp = *stack;
			else
				tmp = tmp2->next;
		}
		else
			stack_iter(&tmp, &tmp2);
	}
}

void	stack0(t_players *stack)
{
	while (stack)
	{
		stack->live = 0;
		stack->live_amount = 0;
		stack = stack->next;
	}
}

void	check_end(t_players *players, byte *map,
				t_players **stack, t_flags *flags)
{
	int		i;

	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (players[i].live + players[i].live_amount == 0
			&& players[i].comands != NULL)
		{
			free(players[i].comands);
			players[i].comands = NULL;
		}
		players[i].live = 0;
		players[i].live_amount = 0;
		i++;
	}
	check_dead_proccess(stack);
	stack0(*stack);
	if (get_alive_players(players) == 0 && *stack == NULL)
		end_game(players, map, stack, flags);
}
