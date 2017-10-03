/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:22:01 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 17:23:01 by mponomar         ###   ########.fr       */
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
	players->live_ptr = NULL;
	players->next = NULL;
	return (players);
}
