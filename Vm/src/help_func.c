/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:17:41 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/28 01:02:42 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int						check_amount(t_flags *flags)
{
	if (flags->amount_players > 4)
	{
		print_error("To many Players, maximum 4.");
		return (0);
	}
	else if (flags->amount_num > 4)
	{
		print_error("To many number of Player. Read usage (Enter ./corewar).");
		return (0);
	}
	else
		return (1);
}

long long int			ft_atoilong(const char *str)
{
	long long int		i;
	long long int		result;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '\200')
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	return (result * sign);
}

char					*ten_hex(int i, char *str, int size)
{
	char				*m;
	char				*tmp;
	int					l;

	l = 0;
	m = (char *)malloc(sizeof(char) * (size + 1));
	*(m + size) = '\0';
	while (l < size)
		m[l++] = '0';
	l--;
	while (i && l >= 0)
	{
		m[l] = HEX[i % 16];
		l--;
		i = i / 16;
	}
	if (!str)
		return (m);
	tmp = ft_strjoin(str, m);
	free(str);
	free(m);
	return (tmp);
}

unsigned int			change_bite(unsigned int num)
{
	unsigned int		fs;
	unsigned int		s;
	unsigned int		t;
	unsigned int		fo;

	fs = num >> 24;
	s = (num << 8) >> 24;
	t = (num << 16) >> 24;
	fo = (num << 24) >> 24;
	num = (fo << 24) + (t << 16) + (s << 8) + fs;
	return (num);
}

int						sort_list(t_players **head, t_flags *flags)
{
	t_players			*new_head;
	t_players			*tmp;
	t_players			*tmp1;

	new_head = NULL;
	tmp = *head;
	tmp1 = NULL;
	if (flags->amount_players == 0)
	{
		print_comands();
		return (0);
	}
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		insert_sorted(&new_head, tmp1);
	}
	*head = new_head;
	rename_players(*head);
	return (1);
}
