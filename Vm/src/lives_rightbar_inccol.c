/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives_rightbar_inccol.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:27:26 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 18:29:27 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	lives_right_row(t_players *players, int die, int y)
{
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 15 + y, 199, "Live breakdown for current period :");
	attroff(COLOR_PAIR(8) | A_BOLD);
	print_row(players, 0, y);
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 18 + y, 199, "Live breakdown for last period :");
	attroff(COLOR_PAIR(8) | A_BOLD);
	print_row(players, 1, y + 3);
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 21 + y, 199, "CYCLE_TO_DIE :        ");
	mvwprintw(stdscr, 21 + y, 199, "CYCLE_TO_DIE : %d", die);
	mvwprintw(stdscr, 23 + y, 199, "CYCLE_DELTA : 50");
	mvwprintw(stdscr, 25 + y, 199, "NBR_LIVE : 21");
	mvwprintw(stdscr, 27 + y, 199, "MAX_CHECKS : 10");
	attroff(COLOR_PAIR(8) | A_BOLD);
}

void	players_right_bar(t_players *players)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		attron(COLOR_PAIR(8) | A_BOLD);
		mvwprintw(stdscr, 11 + k, 199, "Player %d :", players[i].num);
		attroff(COLOR_PAIR(8) | A_BOLD);
		attron(COLOR_PAIR(i + 1) | A_BOLD);
		mvwprintw(stdscr, 11 + k, 211, "%s", players[i].header.prog_name);
		attroff(COLOR_PAIR(i + 1) | A_BOLD);
		attron(COLOR_PAIR(8) | A_BOLD);
		mvwprintw(stdscr, 12 + k, 201, "Last live :");
		mvwprintw(stdscr, 12 + k, 234, "%d", players[i].last_live);
		mvwprintw(stdscr, 13 + k, 201, "Lives in current period :");
		mvwprintw(stdscr, 13 + k, 234, "          ");
		mvwprintw(stdscr, 13 + k, 234, "%d", players[i].live);
		k += 4;
		i++;
	}
}

void	right_bar(t_flags *flags, t_players *players, t_players *stack)
{
	if (flags->paused == 1)
	{
		attron(COLOR_PAIR(6) | A_BOLD);
		mvwprintw(stdscr, 2, 199, "             ");
		mvwprintw(stdscr, 2, 199, "** PAUSED **");
		attroff(COLOR_PAIR(6) | A_BOLD);
	}
	else
	{
		attron(COLOR_PAIR(7) | A_BOLD);
		mvwprintw(stdscr, 2, 199, "             ");
		mvwprintw(stdscr, 2, 199, "** RUNNING **");
		attroff(COLOR_PAIR(7) | A_BOLD);
	}
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 4, 199, "Speed cycles/second : x");
	mvwprintw(stdscr, 4, 222, "        ");
	mvwprintw(stdscr, 4, 222, "%d", flags->speed);
	mvwprintw(stdscr, 7, 199, "Cycle : ");
	mvwprintw(stdscr, 7, 207, "%d", *(players[0].cycles) - 1);
	flags->process = size_processes(&stack) + flags->amount_players;
	mvwprintw(stdscr, 9, 199, "Processes : ");
	mvwprintw(stdscr, 9, 211, "            ");
	mvwprintw(stdscr, 9, 211, "%d", flags->process);
	attroff(COLOR_PAIR(8) | A_BOLD);
}

void	include_colors(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_GREEN);
	init_pair(11, COLOR_BLACK, COLOR_BLUE);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_YELLOW);
	init_pair(100, 241, COLOR_BLACK);
	init_pair(101, 241, 241);
}

void	include_beginer_vis(void)
{
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	cbreak();
	curs_set(0);
	start_color();
	include_colors();
}
