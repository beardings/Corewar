/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:27:29 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 18:28:19 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				main(int argc, char **argv)
{
	t_flags		*flags;
	t_players	*players;

	if (argc < 2)
	{
		print_comands();
		return (0);
	}
	flags = create_flags();
	if ((get_flags(flags, argv)) == 0)
		return (0);
	if ((check_flags_for_players(argc - 1, flags, argv)) == 0)
		return (0);
	players = create_players();
	if ((get_players(players, argv, argc, flags) == 0))
		return (0);
	change_first_reg_players(&players);
	if ((ft_swap_players(&players, flags->amount_players) == 0))
		return (0);
	print_data_players(&players);
	//start_vm(&players, flags->amount_players, flags);
	return (0);
}
