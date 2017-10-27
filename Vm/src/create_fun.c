/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:22:01 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 23:52:00 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_flags			*create_flags(void)
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->dump = -1;
	flags->visual = 0;
	flags->amount_players = 0;
	flags->amount_num = 0;
	flags->paused = 1;
	flags->process = 0;
	flags->speed = 1;
	flags->base = 0;
	flags->cycles = 0;
	flags->die = 0;
	flags->cycles_test = 0;
	flags->max_checks = 0;
	flags->map_color = NULL;
	return (flags);
}

t_players		*create_players(void)
{
	t_players	*players;

	players = (t_players *)malloc(sizeof(t_players));
	players->comands = NULL;
	players->num = -1;
	players->live = 0;
	players->live_amount = 0;
	players->pos = 0;
	players->reg = NULL;
	players->stop = 0;
	players->carry = 0;
	players->cycles = NULL;
	players->last_live = 0;
	players->last_herro = NULL;
	players->curr_com = 0;
	players->st = -1;
	players->next = NULL;
	players->number = 0;
	return (players);
}
