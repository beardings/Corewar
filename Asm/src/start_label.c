/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:57:15 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 15:57:16 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		write_after_label(char **line, t_char *lst, t_label *tp, char **str)
{
	int			i;
	t_command	*tmp;

	i = 0;
	tmp = NULL;
	while (*line && !i)
	{
		return_new_command(tp, &tmp);
		if (!correct_name_command(*str, lst, tmp))
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
		free(*line);
		*line = read_while_empty(*line, lst->fd);
		*str = *line;
		i = label_this(*line);
	}
	if (!*line)
		return (0);
	return (i);
}

char	*return_str_s_l(char *line)
{
	char	*str;

	str = line;
	while (*str != ':')
		str++;
	str++;
	return (str);
}

int		start_label(char **line, t_label *l, t_char *lst)
{
	int		i;
	t_label	*tmp;
	char	*str;

	i = 1;
	while (i == 1)
	{
		tmp = write_label_name(l, *line);
		str = return_str_s_l(*line);
		if (!have_something_after_space(str))
		{
			free(*line);
			*line = read_while_empty(*line, lst->fd);
			str = *line;
			if (!str)
				return (1);
			i = label_this(str);
			if (!i)
				i = write_after_label(line, lst, tmp, &str);
		}
		else
			i = write_after_label(line, lst, tmp, &str);
	}
	return (i);
}
