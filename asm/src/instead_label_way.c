/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instead_label_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:59:38 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/12 14:59:39 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		function_ret_one(char *str, t_label *now, t_label *l)
{
	int		i;
	t_label *s;

	s = l;
	i = -2;
	while (s)
	{
		if (s == now)
		{
			if (s->name && !ft_strcmp(s->name, str))
				return (0);
			if (i == -2)
				i = 0;
			if (i == -1)
				return (-1);
		}
		if (s->name && !ft_strcmp(s->name, str) && i < 2)
			i++;
		s = s->next;
	}
	return (i);
}

char	*calculation(t_cal *cal, t_char *lst, t_command *c, t_label *now)
{
	int				i;
	long long int	x;

	x = 0;
	if (cal->size == 4)
		x = 65535;
	if (cal->size == 8)
		x = 4294967295;
	i = function_ret_one(cal->str, now, cal->lbl);
	if (i == -1)
	{
		i = x - (cal1(cal->lbl, c, lst, cal->str) / 2) + 1;
		return (ten_hex(i, NULL, cal->size));
	}
	else if (i == 0)
	{
		i = cal2(now, c, lst) / 2;
		return (ten_hex(i == 0 ? 0 : x - i + 1, NULL, cal->size));
	}
	else if (i == 1)
	{
		i = cal3(now, c, lst, cal->str) / 2;
		return (ten_hex(i, NULL, cal->size));
	}
	return (NULL);
}

void	cal_eq(t_cal **cal, t_label *l, char *str, int x)
{
	(*cal)->lbl = l;
	(*cal)->str = str;
	(*cal)->size = x * 2;
}

void	go_to_the_cal(t_command *c, t_char *lst, t_label *tmp, t_label *l)
{
	t_cal		*cal;
	int			x;
	int			i;

	cal = (t_cal *)malloc(sizeof(t_cal));
	x = 0;
	i = 0;
	while (i < c->num_param)
	{
		if (c->opcode > 0 && (c->param_type[i] == 20 || c->param_type[i] == 40))
		{
			if (c->param_type[i] == 40)
				x = 2;
			if (c->param_type[i] == 20)
				x = lst->op[c->opcode - 1].label_size;
			if (!x)
				x = 2;
			cal_eq(&cal, l, c->param[i], x);
			cal->tmp = calculation(cal, lst, c, tmp);
			free(c->param[i]);
			c->param[i] = cal->tmp;
		}
		i++;
	}
	free(cal);
}

int		instead_label_way(t_label *l, t_char *lst)
{
	t_label		*tmp;
	t_command	*c;

	tmp = l;
	while (tmp)
	{
		c = tmp->command;
		while (c && c->opcode != -1)
		{
			go_to_the_cal(c, lst, tmp, l);
			c = c->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
