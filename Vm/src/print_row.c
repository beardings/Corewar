/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:34:59 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 18:43:53 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_row_end(int y)
{
	attron(COLOR_PAIR(100) | A_BOLD);
	mvwprintw(stdscr, 16 + y, 250, "]");
	attroff(COLOR_PAIR(100) | A_BOLD);
}

void	print_row_st(int y)
{
	attron(COLOR_PAIR(100) | A_BOLD);
	mvwprintw(stdscr, 16 + y, 199, "[--------------");
	mvwprintw(stdscr, 16 + y, 214, "------------------------------------");
	attroff(COLOR_PAIR(100) | A_BOLD);
}

void	print_row(t_players *players, int point, int y)
{
	int did[4];
	int all;
	int i;

	i = 0;
	all = 0;
	print_row_st(y);
	while (players[i].header.prog_name[0] != '\0')
	{
		if (point == 0)
		{
			did[i] = players[i].live;
			all = all + players[i].live;
		}
		else if (point == 1)
		{
			did[i] = players[i].last_live;
			all = all + players[i].last_live;
		}
		i++;
	}
	if ((print_rc_next(did)) > 0)
		print_rc(all, print_rc_next(did), did, y);
	print_row_end(y);
}
