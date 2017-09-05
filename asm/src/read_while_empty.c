/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_while_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:07:21 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 13:07:21 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		comment_this_line(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	if (*line == '#')
		return (1);
	return (0);
}

char	*read_while_empty(char *line, int fd)
{
	int		d;

	d = 0;
	line = NULL;
	while ((d = get_next_line(fd, &line)) > 0)
	{
		if (line && *line && have_something_after_space(line)\
			&& !comment_this_line(line))
			break ;
		else
		{
			free(line);
			line = NULL;
		}
	}
	return (line);
}
