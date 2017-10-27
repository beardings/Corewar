/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_vm_vis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:35:47 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 23:36:17 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	go_vm_vis(t_players *players, int count, t_flags *flags)
{
	byte		*map;
	t_players	*stack;
	int			i;

	i = 0;
	flags->cycles = 1;
	flags->cycles_test = 1;
	flags->DIE = CYCLE_TO_DIE;
	flags->max_checks = 0;
	map = get_map(players, count, &(flags->cycles));
	flags->map_color = get_map_color(players, count, &(flags->cycles));
	include_beginer_vis();
	while (players[i].header.prog_name[0] != '\0')
		get_stop(&(players[i++]), map);
	while (flags->DIE > 0)
	{
		if (flags->paused == 0)
		{
			main_cycle(players, map, &stack, flags);
			get_color(players, &stack, flags);
			check_all(players, map, &stack, flags);
			include_refresh_vis(players, flags, stack, map);
			usleep(100000 / flags->speed);
			flags->cycles++;
			flags->cycles_test++;
		}
		else
			include_refresh_vis(players, flags, stack, map);
	}
	end_game(players, map, &stack, flags);
}
