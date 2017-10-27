#include "../includes/vm.h"

void	get_color_next(t_players **stack, t_flags *flags)
{
	t_players *tmp;
	int k;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->st > -1)
		{
			k = 0;
			while (k < 4)
			{
				flags->map_color[tmp->st] = tmp->number;
				tmp->st++;
				if (tmp->st == MEM_SIZE)
					tmp->st = 0;
				k++;
			}
			tmp->st = -1;
		}
		tmp = tmp->next;
	}
}

void	get_color(t_players *players, t_players **stack, t_flags *flags)
{
	int i;
	int k;

	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (players[i].st > -1)
		{
			k = 0;
			while (k < 4)
			{
				flags->map_color[players[i].st] =  i + 1;
				players[i].st++;
				if (players[i].st == MEM_SIZE)
					players[i].st = 0;
				k++;
			}
			players[i].st = -1;
		}
		i++;
	}
	get_color_next(stack, flags);
}

void    refresh_cursor_next(t_flags *flags, t_players *stack, byte *map)
{
	t_players	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (flags->map_color[tmp->pos] == 0)
			attron(COLOR_PAIR(101));
		else
			attron(COLOR_PAIR(flags->map_color[tmp->pos] + 9));
		mvwprintw(stdscr, (tmp->pos / 64) + 2, (tmp->pos % 64) * 3 + 3, "%02x", map[tmp->pos]);
		if (flags->map_color[tmp->pos] == 0)
			attroff(COLOR_PAIR(101));
		else
			attroff(COLOR_PAIR(flags->map_color[tmp->pos] + 9));
		mvwprintw(stdscr, (tmp->pos / 64) + 2, (tmp->pos % 64) * 3 + 5, " ");
		tmp = tmp->next;
	}
}

void	refresh_cursor(t_players *players, t_flags *flags, t_players *stack, byte *map)
{
	int 		i;

	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (flags->map_color[players[i].pos] == 0)
			attron(COLOR_PAIR(101));
		else
			attron(COLOR_PAIR(flags->map_color[players[i].pos] + 9));
		mvwprintw(stdscr, (players[i].pos / 64) + 2, (players[i].pos % 64) * 3 + 3, "%02x", map[players[i].pos]);
		if (flags->map_color[players[i].pos] == 0)
			attroff(COLOR_PAIR(101));
		else
			attroff(COLOR_PAIR(flags->map_color[players[i].pos] + 9));
		mvwprintw(stdscr, (players[i].pos / 64) + 2, (players[i].pos % 64) * 3 + 5, " ");
		i++;
	}
	refresh_cursor_next(flags, stack, map);
}

void	include_refresh_vis(t_players *players, t_flags *flags, t_players *stack, byte *map)
{
	noecho();
	print_board();
	print_new_map(map, flags->map_color);
	right_bar(flags, players, stack);
	players_right_bar(players);
	if (flags->amount_players == 1)
		lives_right_row(players, flags->DIE, 0);
	else if (flags->amount_players == 2)
		lives_right_row(players, flags->DIE, 4);
	else if (flags->amount_players == 3)
		lives_right_row(players, flags->DIE, 8);
	else if (flags->amount_players == 4)
		lives_right_row(players, flags->DIE, 12);
	refresh_cursor(players, flags, stack, map);
	board_kay(flags);
	refresh();
}