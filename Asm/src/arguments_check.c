/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:47:41 by ngulya            #+#    #+#             */
/*   Updated: 2017/08/02 11:47:42 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_t_dir(char *arg, int size, t_command *c, int i)
{
	if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
	{
		c->param_type[i] = T_DIR * 10;
		c->param[i] = ft_strdup(&arg[2]);
	}
	else if (arg[0] == DIRECT_CHAR && arg[1] != '+' && ft_isanbr(&arg[1]))
	{
		c->param_type[i] = T_DIR;
		c->param[i] = ten_hex(most_long_long(&arg[1]), NULL, size * 2);
	}
	else
		return (0);
	return (T_DIR);
}

int		is_t_ind(char *arg, t_command *c, int i)
{
	if (arg[0] == LABEL_CHAR)
	{
		c->param_type[i] = T_IND * 10;
		c->param[i] = ft_strdup(&arg[1]);
	}
	else if (arg[0] != '+' && ft_isanbr(arg))
	{
		c->param_type[i] = T_IND;
		c->param[i] = ten_hex(most_long_long(arg), NULL, IND_SIZE * 2);
	}
	else
		return (0);
	return (T_IND);
}

int		is_t_reg(char *arg, t_command *c, int i)
{
	if (!arg || arg[0] != 'r' || !ft_isanbr(&arg[1]) || arg[0] == '0'
		|| ft_atoi(&arg[1]) > REG_NUMBER || ft_atoi(&arg[1]) < 1)
	{
		return (0);
	}
	c->param_type[i] = T_REG;
	c->param[i] = ten_hex(ft_atoi(&arg[1]), NULL, 2);
	return (T_REG);
}
