/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 17:55:40 by liabanzh          #+#    #+#             */
/*   Updated: 2017/07/18 17:55:41 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	get_stop(t_players *player, byte *map)
{
	int 	stop[16] = {9, 4, 4, 9, 9, 5, 5, 5, 19, 24, 24,
						799, 9, 49, 999, 1};
	if (map[player->pos % MEM_SIZE] > 0 && map[player->pos % MEM_SIZE] <= 16)
		player->stop = stop[map[player->pos % MEM_SIZE] - 1];
	else
		player->stop = 0;
	player->curr_com = map[player->pos % MEM_SIZE];
}

void	delete_split(char ***split)
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
	int	value;
	int	sign;

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

void	get_map_dop(byte *map, char **ptr, int i)
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

byte	*get_map(t_players *players, int count, int *cycles)
{
	unsigned char	*map;
	int				i;
	int				j;
	char			*ptr;

	j = 1;
	i = 0;
	map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	ptr = players[0].comands;
	players[0].cycles = cycles;
	while (i < MEM_SIZE && j <= count)
	{
		if (i >= (MEM_SIZE / count) * j)
		{
			ptr = players[j].comands;
			players[j].cycles = cycles;
			j++;
		}
		get_map_dop(map, &ptr, i);
		i++;
	}
	return (map);
}

void	get_command2(t_players *player, byte *map, t_players **stack)
{
	if (player->curr_com == 6)
		and_xor(player, map, 'a');
	else if (player->curr_com == 7)
		and_xor(player, map, 'o');
	else if (player->curr_com == 8)
		and_xor(player, map, 'x');
	else if (player->curr_com == 9)
		zjmp(player, map);
	else if (player->curr_com == 10)
		ldi(player, map);
	else if (player->curr_com == 11)
		sti(player, map);
	else if (player->curr_com == 12)
		fork_func(player, map, stack);
	else if (player->curr_com == 13)
		lld(player, map);
	else if (player->curr_com == 14)
		lldi(player, map);
	else if (player->curr_com == 15)
		lfork_func(player, map, stack);
	else if (player->curr_com == 16)
		aff(player, map);
	else
		player->pos += 1;
}

void	get_command(t_players *player, byte *map, t_players **stack,
					t_players *players)
{
	if (player->stop == 0)
	{
		if (player->curr_com == 1)
			live(players, map, player);
		else if (player->curr_com == 2)
			ld(player, map);
		else if (player->curr_com == 3)
			st(player, map);
		else if (player->curr_com == 4)
			add(player, map);
		else if (player->curr_com == 5)
			sub(player, map);
		else
			get_command2(player, map, stack);
		player->pos = player->pos % MEM_SIZE;
		get_stop(player, map);
	}
	else
		player->stop -= 1;
}

int 	get_alive_players(t_players *players)
{
	int 		res;
	int 		i;
	t_players	*tmp;

	res = 0;
	i = 0;
	tmp = players;
	while (tmp[i].header.prog_name[0] != '\0')
	{
		if (tmp[i].comands != NULL)
			res++;
		i++;
	}
	return (res);
}

int 	get_last(t_players *players)
{
	int 		i;
	int 		res;

	i = 0;
	res = i;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (*(players[i].last_herro) == players[i].num)
			res = i;
		if (players[i].comands != NULL)
			free(players[i].comands);
		i++;
	}
	return (res);
}

void	end_game_viz(t_players *players, t_flags *flags, int i)
{
	int 	ch;
	int 	y;

	y = (flags->amount_players - 1) * 4;
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 30 + y, 199, "The winner is : ");
	attroff(COLOR_PAIR(8) | A_BOLD);
	attron(COLOR_PAIR(i + 1) | A_BOLD);
	mvwprintw(stdscr, 30 + y, 215, "%s", players[i].header.prog_name);
	attroff(COLOR_PAIR(i + 1) | A_BOLD);
	attron(COLOR_PAIR(8) | A_BOLD);
	mvwprintw(stdscr, 32 + y , 199, "Press 'Esc' to finish.");
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

void	end_game_simple(t_players *players, int i)
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

void	end_game(t_players *players, byte *map, t_players **stack, t_flags *flags)
{
	int 		i;
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

int 	get_lives(t_players *players, t_players *stack)
{
	int 		res;
	int 		i;

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

int 	check_count_proccess(t_players *stack)
{
	int 	res;

	res = 0;
	while (stack)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}

void	stack_iter(t_players **tmp, t_players **tmp2)
{
	(*tmp)->live = 0;
	(*tmp)->live_amount = 0;
	*tmp2 = *tmp;
	*tmp = (*tmp)->next;
}

void	check_dead_proccess(t_players **stack)
{
	t_players	*tmp;
	t_players	*tmp2;

	tmp = *stack;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->live + tmp->live_amount == 0)
		{
			if (tmp2 == NULL)
				*stack = tmp->next;
			else
				tmp2->next = tmp->next;
			free(tmp->reg);
			tmp->reg = NULL;
			free(tmp);
			if (tmp2 == NULL)
				tmp = *stack;
			else
				tmp = tmp2->next;
		}
		else
			stack_iter(&tmp, &tmp2);
	}
}

void	stack0(t_players *stack)
{
	while (stack)
	{
		stack->live = 0;
		stack->live_amount = 0;
		stack = stack->next;
	}
}

void	check_end(t_players *players, byte *map, t_players **stack, t_flags *flags)
{
	int 	i;

	i = 0;
	while (players[i].header.prog_name[0] != '\0')
	{
		if (players[i].live + players[i].live_amount == 0
			&& players[i].comands != NULL)
		{
			free(players[i].comands);
			players[i].comands = NULL;
		}
		players[i].live = 0;
		players[i].live_amount = 0;
		i++;
	}
	check_dead_proccess(stack);
	stack0(*stack);
	if (get_alive_players(players) == 0 && *stack == NULL)
		end_game(players, map, stack, flags);
}

void	print_map(byte *map)
{
	int 	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n0x%04x : ", i);
		printf("%02x ", map[i]);
		i++;
	}
	printf("\n\n");
}

void	check_all(t_players *players, byte *map, t_players **stack, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->cycles_test >= flags->DIE)
	{
		if (get_lives(players, *stack) >= NBR_LIVE || flags->max_checks == 10)
		{
			flags->DIE -= CYCLE_DELTA;
			flags->max_checks = 0;
		}
		else
			flags->max_checks++;
		check_end(players, map, stack, flags);
		flags->cycles_test = 0;
	}
}

void	main_cycle(t_players *players, byte *map, t_players **stack, t_flags *flags)
{
	int			i;
	t_players	*tmp;

	i = 0;
	if (flags->dump == flags->cycles && flags->visual == 0)
		print_map(map);
	tmp = *stack;
	while (tmp != NULL)
	{
		get_command(tmp, map, stack, players);
		tmp = tmp->next;
	}
	i = flags->amount_players - 1;
	while (i >= 0)
	{
		if (players[i].comands != NULL)
			get_command(&(players[i]), map, stack, players);
		i--;
	}
}

void	go_vm(t_players *players, int count, t_flags *flags)
{
	byte		*map;
	t_players	*stack;
	int 		i;

	i = 0;
	flags->cycles = 1;
	flags->cycles_test = 1;
	flags->DIE = CYCLE_TO_DIE;
	flags->max_checks = 0;
	map = get_map(players, count, &(flags->cycles));
	while (players[i].header.prog_name[0] != '\0')
		get_stop(&(players[i++]), map);
	while (flags->DIE > 0)
	{
		main_cycle(players, map, &stack, flags);
		check_all(players, map, &stack, flags);
		flags->cycles++;
		flags->cycles_test++;
	}
	end_game(players, map, &stack, flags);
}
