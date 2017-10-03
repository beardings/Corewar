/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:11:43 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 17:15:20 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_error(char *str)
{
	printf(RED"ERROR!"END);
	printf(" %s\n", str);
}

void	print_comands(void)
{
	printf("\n");
	printf("Usage: ./corewar [-d N -v] <[-n N] champion1.cor> <[-n N] ...>\n");
	printf("--------------------------------------------------------------\n");
	printf("    -d N         : Dumps memory after N cycles then exits\n");
	printf("                   If all battle is less than N cycles,\n");
	printf("                   program will display the last cycle\n");
	printf("--------------------------------------------------------------\n");
	printf("    -n N         : Means that Player after this flag will be\n");
	printf("                   Player number N. If there is no -n flag,\n");
	printf("                   the next available number will be given to\n");
	printf("                   layer, starting from 1\n");
	printf("--------------------------------------------------------------\n");
	printf("    -v           : Visual output mode\n");
	printf("--------------------------------------------------------------\n");
	printf("\n");
}

void	print_data_players(t_players **players)
{
	t_players *tmp;

	tmp = *players;
	if (tmp->header.magic == 0)
		return ;
	while (tmp != NULL)
	{
		printf("* Player %d, weighing", tmp->num);
		printf(" %u bytes,", tmp->header.prog_size);
		printf(" <%s> (%s) !\n", tmp->header.prog_name, tmp->header.comment);
		tmp = tmp->next;
	}
}
