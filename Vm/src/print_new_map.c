/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:16:56 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 18:21:00 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#define START() i = 0, x = 3, y = 2

void		print_new_map_func(char *tmp, int y, int x, int color)
{
	attron(COLOR_PAIR(color));
	mvwprintw(stdscr, y, x, "%s ", tmp);
	attroff(COLOR_PAIR(color));
}

void		print_new_map_zero(char *tmp, int y, int x, int color)
{
	attron(COLOR_PAIR(color) | A_BOLD);
	mvwprintw(stdscr, y, x, "%s ", tmp);
	attroff(COLOR_PAIR(color) | A_BOLD);
}

void		print_new_map(t_byte *map, t_byte *map_color)
{
	int		i;
	int		y;
	int		x;
	char	*tmp;

	START();
	while (i < MEM_SIZE)
	{
		x > 192 ? y++ : 0;
		x > 192 ? x = 3 : 0;
		tmp = get_hex(map[i]);
		if (map_color[i] == 1)
			print_new_map_func(tmp, y, x, 1);
		else if (map_color[i] == 2)
			print_new_map_func(tmp, y, x, 2);
		else if (map_color[i] == 3)
			print_new_map_func(tmp, y, x, 3);
		else if (map_color[i] == 4)
			print_new_map_func(tmp, y, x, 4);
		else
			print_new_map_zero(tmp, y, x, 100);
		free(tmp);
		x += 3;
		i++;
	}
}
