/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_head.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:36:40 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/27 23:46:31 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		get_stop(t_players *player, byte *map)
{
	int		stop[16];

	stop[0] = 9;
	stop[1] = 4;
	stop[2] = 4;
	stop[3] = 9;
	stop[4] = 9;
	stop[5] = 5;
	stop[6] = 5;
	stop[7] = 5;
	stop[8] = 19;
	stop[9] = 24;
	stop[10] = 24;
	stop[11] = 799;
	stop[12] = 9;
	stop[13] = 49;
	stop[14] = 999;
	stop[15] = 1;
	if (map[player->pos % MEM_SIZE] > 0 && map[player->pos % MEM_SIZE] <= 16)
		player->stop = stop[map[player->pos % MEM_SIZE] - 1];
	else
		player->stop = 0;
	player->curr_com = map[player->pos % MEM_SIZE];
}

void		delete_split(char ***split)
{
	int		i;

	i = 0;
	while (*split[i] != NULL)
	{
		free(*split[i]);
		*split[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= ('a' + base - 10)));
}

int			atoi_base_livas(const char *str, int base)
{
	int		value;
	int		sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'a' >= 0)
			value = value * base + (*str - 'a' + 10);
		else if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}

void		get_map_dop(byte *map, char **ptr, int i)
{
	char	*tmp;

	if (*ptr != NULL && **ptr != '\0')
	{
		tmp = ft_strnew(2);
		map[i] = atoi_base_livas(ft_strncpy(tmp, *ptr, 2), 16);
		*ptr = *ptr + 2;
		free(tmp);
	}
	else
		map[i] = 0;
}
