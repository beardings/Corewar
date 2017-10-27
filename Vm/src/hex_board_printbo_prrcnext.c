/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_board_printbo_prrcnext.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:23:56 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 18:26:23 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char			*get_hex(byte val)
{
	char		*tmp;
	char		*res;

	tmp = livas_base(val, 16);
	res = ft_strnew(2);
	if (ft_strlen(tmp) == 1)
	{
		res[1] = tmp[0];
		res[0] = '0';
	}
	else
		return (tmp);
	free(tmp);
	return (res);
}

void			board_kay(t_flags *flags)
{
	int			ch;

	noecho();
	ch = getch();
	if (ch == 113)
		flags->speed > 1 ? flags->speed-- : 0;
	else if (ch == 101)
	{
		if (flags->speed < 250)
			flags->speed++;
	}
	else if (ch == 32)
	{
		if (flags->paused == 0)
			flags->paused = 1;
		else
			flags->paused = 0;
	}
	else if (ch == 27)
	{
		endwin();
		exit(1);
	}
}

void			print_board(void)
{
	int			i;

	i = 0;
	attron(COLOR_PAIR(101));
	while (i < 254)
	{
		mvwprintw(stdscr, 0, i, "*");
		mvwprintw(stdscr, 67, i, "*");
		i++;
	}
	i = 0;
	while (i < 67)
	{
		mvwprintw(stdscr, i, 0, "*");
		mvwprintw(stdscr, i, 253, "*");
		mvwprintw(stdscr, i, 196, "*");
		i++;
	}
	attroff(COLOR_PAIR(101));
}

int				size_processes(t_players **stack)
{
	t_players	*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int				print_rc_next(int *did)
{
	int			i;
	int			size;

	size = 0;
	i = 0;
	while (i < 4)
	{
		if (did[i] > 0)
			size++;
		i++;
	}
	return (size);
}
