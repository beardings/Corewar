/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_center.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 00:51:57 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/28 00:54:32 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			end_game_viz(t_players *players, t_flags *flags, int i)
{
	int			ch;
	int			y;

	y = (flags->amount_players - 1) * 4;
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 30 + y, 199, "The winner is : ");
	attroff(COLOR_PAIR(8) | A_BOLD);
	attron(COLOR_PAIR(i + 1) | A_BOLD);
	mvwprintw(stdscr, 30 + y, 215, "%s", players[i].header.prog_name);
	attroff(COLOR_PAIR(i + 1) | A_BOLD);
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 32 + y, 199, "Press 'Esc' to finish.");
	attroff(COLOR_PAIR(8) | A_BOLD);
	i = 0;
	while (players[i].header.prog_name[0] != '\0')
		free(players[i++].reg);
	while (1)
	{
		if ((ch = getch()) == 27)
		{
			endwin();
			exit(1);
		}
	}
}

void			end_game_simple(t_players *players, int i)
{
	printf("Contestant %d \'%s\', has won!\n", players[i].num * -1,
			players[i].header.prog_name);
	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		free(players[i].reg);
		players[i].reg = NULL;
		i++;
	}
	exit(1);
}

void			end_game(t_players *players, t_byte *map,
						t_players **stack, t_flags *flags)
{
	int			i;
	t_players	*tmp;
	t_players	*tmp2;

	free(map);
	map = NULL;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp->reg);
		free(tmp);
		tmp = tmp2;
	}
	*stack = NULL;
	i = get_last(players);
	if (flags->visual == 0)
		end_game_simple(players, i);
	else
		end_game_viz(players, flags, i);
}

int				get_lives(t_players *players, t_players *stack)
{
	int			res;
	int			i;

	res = 0;
	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		res += players[i].live + players[i].live_amount;
		i++;
	}
	while (stack)
	{
		res += stack->live;
		stack = stack->next;
	}
	return (res);
}

int				check_count_proccess(t_players *stack)
{
	int			res;

	res = 0;
	while (stack)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}
