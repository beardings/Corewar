/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:46:55 by ybelilov          #+#    #+#             */
/*   Updated: 2017/07/10 14:46:56 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			func_par_val_norm(char *arg, char **str)
{
	char	*ls;
	int		l;

	if (!arg)
		return (0);
	l = check_for_comment_at_the_end(arg);
	if (l > 0)
	{
		ls = ft_strndup(arg, l);
		*str = delete_fuck(&ls);
		if (!*str)
			return (0);
	}
	else
		*str = ft_strdup(arg);
	return (1);
}

int			cycle_while(t_char *main, char **arg, t_command *cmd, int k)
{
	int		i;
	int		res;
	int		po;

	i = 0;
	while (i < k)
	{
		res = is_t_dir(arg[i], main->op[cmd->opcode - 1].label_size, cmd, i)\
		+ is_t_ind(arg[i], cmd, i)\
		+ is_t_reg(arg[i], cmd, i);
		po = main->op[cmd->opcode - 1].r_d_i[i];
		if ((po == 7 && res != 0) || (res != 0 && \
			(po == res || po - res == 2 || po - res == 4 || po - res == 1)))
			;
		else
		{
			ft_freearray(arg);
			return (0);
		}
		i++;
	}
	return (1);
}

int			parameter_validation(t_char *main, t_command *cmd, char *com)
{
	char	**arg;
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (!func_par_val_norm(com, &str))
		return (0);
	arg = ft_array_trim(ft_strsplit(str, ','));
	if (!arg || main->op[cmd->opcode - 1].arguments != array_len(arg))
	{
		free(str);
		ft_freearray(arg);
		return (0);
	}
	if (!cycle_while(main, arg, cmd, array_len(arg)))
	{
		free(str);
		return (0);
	}
	cmd->num_param = main->op[cmd->opcode - 1].arguments;
	ft_freearray(arg);
	free(str);
	return (1);
}

int			check_for_comment_at_the_end(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '#')
			return (i);
		i++;
		str++;
	}
	return (0);
}
