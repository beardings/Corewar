/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:36:08 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 19:37:23 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		print_rc_end(int skiko, int color, int pos, int y)
{
	int		i;

	i = 0;
	while (i < skiko)
	{
		attron(COLOR_PAIR(color + 1));
		mvwprintw(stdscr, y, pos + i, "-");
		attroff(COLOR_PAIR(color + 1));
		i++;
	}
}

void		print_rc_n(int all, int *did, int y, int *sk)
{
	sk[0] = find_i(&sk[2], did, 50, all);
	sk[1] = sk[0];
	print_rc_end(sk[0], sk[2], 200, 16 + y);
	sk[2]++;
	sk[0] = 50 - sk[0];
	find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
}

void		print_rc_nn(int all, int *did, int y, int *sk)
{
	sk[0] = find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200, 16 + y);
	sk[1] = sk[0];
	sk[2]++;
	sk[0] = find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
	sk[1] += sk[0];
	sk[2]++;
	sk[0] = 50 - sk[1];
	find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
}

void		print_rc_nnn(int all, int *did, int y, int *sk)
{
	sk[0] = find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200, 16 + y);
	sk[1] = sk[0];
	sk[2]++;
	sk[0] = find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
	sk[1] += sk[0];
	sk[2]++;
	sk[0] = find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
	sk[1] += sk[0];
	sk[2]++;
	sk[0] = 50 - sk[1];
	find_i(&sk[2], did, 50, all);
	print_rc_end(sk[0], sk[2], 200 + sk[1], 16 + y);
}

void		print_rc(int all, int size, int *did, int y)
{
	int		sk[3];

	sk[2] = 0;
	if (size == 1)
	{
		while (sk[2] < 4)
		{
			if (did[sk[2]] > 0)
				break ;
			sk[2]++;
		}
		print_rc_end(50, sk[2], 200, 16 + y);
	}
	else if (size == 2)
		print_rc_n(all, did, y, sk);
	else if (size == 3)
		print_rc_nn(all, did, y, sk);
	else if (size == 4)
		print_rc_nnn(all, did, y, sk);
}
