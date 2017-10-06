/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:42:24 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 18:00:40 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void				get_another_data(t_players **tmp, int fd)
{
	unsigned char	*com;
	char			*str;
	int				i;

	i = 0;
	str = NULL;
	com = malloc(((*tmp)->header.prog_size));
	read(fd, com, (*tmp)->header.prog_size);
	while (i < (int)(*tmp)->header.prog_size)
	{
		str = ten_hex((int)com[i], str, 2);
		i++;
	}
	free(com);
	(*tmp)->comands = str;
}

int					check_cor_file(t_players **tmp, char *cor_file)
{
	int				fd;
	t_header		*header;
	char			*str;

	str = malloc(sizeof(char *) * sizeof(t_header));
	fd = open(cor_file, O_RDONLY);
	read(fd, str, sizeof(t_header));
	header = (t_header *)str;
	header->magic = change_bite(header->magic);
	header->prog_size = change_bite(header->prog_size);
	if (header->prog_size > CHAMP_MAX_SIZE)
	{
		free(header);
		print_error("Program size the bigger then max size.");
		return (0);
	}
	if (header->magic != COREWAR_EXEC_MAGIC)
	{
		free(header);
		print_error("Magic kay are not correct.");
		return (0);
	}
	(*tmp)->header = *header;
	get_another_data(tmp, fd);
	free(str);
	return (1);
}

int					check_valid_player_num(char *num)
{
	if (!is_digit(num))
	{
		print_error("Player number must be a number");
		return (0);
	}
	if (ft_atoilong(num) > INT_MAX)
	{
		print_error("Player number must not be greater than maxint");
		return (0);
	}
	return (1);
}

int					get_players_n(t_players *players, char **argv, int *i)
{
	if (!(ft_strcmp(argv[*i], "-n")))
	{
		if (!check_valid_player_num(argv[*i + 1]))
			return (0);
		players->num = ft_atoi(argv[*i + 1]);
		*i += 2;
		if ((check_cor_file(&players, argv[*i]) == 0))
			return (0);
	}
	else
	{
		if ((check_cor_file(&players, argv[*i]) == 0))
			return (0);
	}
	return (1);
}

int					get_players(t_players *players,
								char **argv, int argc, t_flags *flags)
{
	t_players		*tmp;
	int				i;

	tmp = players;
	i = 1;
	flags->dump > -1 ? i += 2 : 0;
	flags->visual > 0 ? i++ : 0;
	while (i < argc)
	{
		if ((get_players_n(players, argv, &i)) == 0)
			return (0);
		i++;
		while (players->next != NULL)
			players = players->next;
		i != argc ? players->next = create_players() : 0;
		i != argc ? players = players->next : 0;
	}
	players = tmp;
	return (1);
}
