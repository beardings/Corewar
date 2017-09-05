/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_name_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:25:05 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/08 17:25:06 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		correct_name_command(char *line, t_char *lst, t_command *s)
{
	int		j;
	int		i;
	char	*tmp;

	i = 0;
	j = 0;
	while (line && *line && (*line == ' ' || *line == '\t'))
		line++;
	if (!line || !*line)
		return (0);
	tmp = line;
	while (*tmp && (*tmp != ' ' && *tmp != '\t'))
	{
		tmp++;
		j++;
	}
	while (*tmp && i < 16 && ft_strncmp(line, lst->op[i].name, j))
		i++;
	if (*tmp && i < 16 && !ft_strncmp(line, lst->op[i].name, j))
	{
		s->opcode = i + 1;
		return (parameter_validation(lst, s, tmp));
	}
	return (0);
}
