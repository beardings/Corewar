/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_char_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:06:27 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 13:06:28 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		correct_label_char(char *str, int size)
{
	int		i;
	int		j;

	j = 0;
	while (*str && *str != ':' && size > 0)
	{
		i = 0;
		while (i < 37)
		{
			if (*str == LABEL_CHARS[i])
				break ;
			i++;
		}
		if (i == 37)
			return (0);
		str++;
		j++;
		size--;
	}
	if (!*str)
		return (0);
	return (j);
}

int		return_after_spac_tab_str(char *str)
{
	int		i;

	i = 0;
	while (*str && (*str == ' ' || *str == '\t'))
	{
		str++;
		i++;
	}
	return (i);
}

int		func_for_correct_c_n(int j, int size, char *line2)
{
	if (j > size || (j == 0 && size == 126))
		return (0);
	line2++;
	while (*line2)
	{
		if (*line2 == '#')
			return (1);
		if (*line2 && *line2 != ' ' && *line2 != '\t')
			return (0);
		line2++;
	}
	return (1);
}

int		zaebali_normu(char **str, char **line2, int j)
{
	char	*tmp;

	tmp = ft_strjoin(*str, "\n");
	free(*str);
	*str = tmp;
	tmp = ft_strjoin(*str, *line2);
	free(*str);
	*str = tmp;
	tmp = *line2;
	j = go_to_znak(line2, j);
	free(tmp);
	return (j);
}

int		correct_char_name(char **str, int size, int fd, int plus)
{
	int		j;
	int		pl2;
	char	*line;
	char	*line2;

	j = 0;
	line2 = NULL;
	pl2 = return_after_spac_tab_str(*str + plus) + plus;
	if (*((*str) + pl2) != '"')
		return (0);
	else
		line = *str + 1 + pl2;
	j = go_to_znak(&line, j);
	if (!*line && j < size)
	{
		while (get_next_line(fd, &line2))
		{
			j = zaebali_normu(str, &line2, j);
			if (*line2 == '"' || j > size)
				break ;
		}
	}
	else
		line2 = line;
	return (func_for_correct_c_n(j, size, line2));
}
