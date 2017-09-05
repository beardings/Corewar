/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:23:06 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/06 14:23:06 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		function_for_first_time(t_label **l)
{
	t_command	*s;
	char		**tmp;

	(*l)->command = (t_command *)malloc(sizeof(t_command));
	s = (*l)->command;
	s->opcode = -1;
	s->num_param = 0;
	s->param_type[0] = 0;
	s->param_type[1] = 0;
	s->param_type[2] = 0;
	s->param = (char **)malloc(sizeof(char *) * 3);
	tmp = s->param;
	tmp[0] = NULL;
	tmp[1] = NULL;
	tmp[2] = NULL;
	s->next = NULL;
	(*l)->name = NULL;
	(*l)->command = s;
	(*l)->next = NULL;
}

int			write_before_label(char **line, t_char *lst, t_label *l)
{
	int			i;
	t_command	*tmp;

	i = 0;
	tmp = NULL;
	while (!i)
	{
		return_new_command(l, &tmp);
		if (!correct_name_command(*line, lst, tmp))
			return (-1);
		free(*line);
		*line = read_while_empty(*line, lst->fd);
		i = label_this(*line);
	}
	if (!*line)
		return (0);
	return (i);
}

void		free_opcode_minus(t_label **l)
{
	if ((*l)->command->opcode == -1)
	{
		free((*l)->command->param);
		free((*l)->command);
		(*l)->command = NULL;
	}
}

t_label		*byte_go(int fd, t_char *lst)
{
	char		*line;
	int			i;
	t_label		*l;

	lst->fd = fd;
	line = NULL;
	l = (t_label *)malloc(sizeof(t_label));
	function_for_first_time(&l);
	line = read_while_empty(line, lst->fd);
	i = label_this(line);
	if (!i)
		i = write_before_label(&line, lst, l);
	if (i == 1)
		i = start_label(&line, l, lst);
	if (line)
		free(line);
	free_opcode_minus(&l);
	if (i == -1 || !valid_label(l))
	{
		free_label(l);
		return (NULL);
	}
	prog_size(lst, l);
	instead_label_way(l, lst);
	return (l);
}
