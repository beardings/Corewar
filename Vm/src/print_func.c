/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:11:43 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/09 19:57:45 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_error(char *str)
{
	ft_printf(RED"ERROR!"END);
	ft_printf(" %s\n", str);
}

void	print_comands(void)
{
	ft_printf("\n");
	ft_printf("Usage: ./corewar [-d N -v] <[-n N]");
	ft_printf(" champion1.cor> <[-n N] ...>\n");
	ft_printf("------------------------------");
	ft_printf("--------------------------------\n");
	ft_printf("    -d N         : Dumps memory after N cycles then exits\n");
	ft_printf("------------------------------");
	ft_printf("--------------------------------\n");
	ft_printf("    -n N         : Means that Player after this flag will be\n");
	ft_printf("                   Player number N. If there is no -n flag,\n");
	ft_printf("                   the next available number ");
	ft_printf("will be given to\n");
	ft_printf("                   layer, starting from 1\n");
	ft_printf("------------------------------");
	ft_printf("--------------------------------\n");
	ft_printf("    -v           : Visual output mode\n");
	ft_printf("------------------------------");
	ft_printf("--------------------------------\n");
	ft_printf("\n");
}

void	print_data_players(t_players **players)
{
	t_players *tmp;

	tmp = *players;
	if (tmp->header.magic == 0)
		return ;
	while (tmp != NULL)
	{
		ft_printf("* Player %d, weighing", tmp->num);
		ft_printf(" %u bytes,", tmp->header.prog_size);
		ft_printf(" <%s> (%s) !\n", tmp->header.prog_name, tmp->header.comment);
		tmp = tmp->next;
	}
}
