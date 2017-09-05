/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:18:05 by ngulya            #+#    #+#             */
/*   Updated: 2017/02/10 17:06:41 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gn	*correct_struct(t_gn **list, int fd)
{
	t_gn	*str;
	t_gn	*new;

	if (*list == NULL)
	{
		(*list) = (t_gn*)malloc(sizeof(t_gn));
		(*list)->fd = fd;
		(*list)->str = NULL;
		(*list)->next = NULL;
	}
	str = *list;
	while (str != NULL)
	{
		new = str;
		if (str->fd == fd)
			return (str);
		str = str->next;
	}
	new->next = (t_gn*)malloc(sizeof(t_gn));
	new = new->next;
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	return (new);
}

void	rewrite(t_gn **str, char *res)
{
	char	*tmp;

	if ((*str)->str == NULL)
		(*str)->str = ft_strdup(res);
	else
	{
		tmp = ft_strjoin((*str)->str, res);
		ft_strdel(&((*str)->str));
		(*str)->str = tmp;
	}
}

int		write_s(char *res, t_gn **str, char **line)
{
	char	*tmp;

	tmp = ft_strchr(res, '\n');
	*tmp = '\0';
	rewrite(str, res);
	*line = ft_strdup((*str)->str);
	ft_strdel(&((*str)->str));
	if (*(tmp + 1))
		(*str)->str = ft_strdup(tmp + 1);
	ft_strdel(&res);
	return (1);
}

int		correct_s(t_gn **str, char **line)
{
	char	*tmp;
	char	*tmp_s;

	tmp = NULL;
	if ((*str)->str)
		tmp = ft_strchr((*str)->str, '\n');
	if (tmp == NULL)
		return (0);
	*tmp = '\0';
	*line = ft_strdup((*str)->str);
	if (!*(tmp + 1))
		ft_strdel(&((*str)->str));
	else
	{
		tmp_s = ft_strdup(tmp + 1);
		ft_strdel(&((*str)->str));
		(*str)->str = tmp_s;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*res;
	static	t_gn	*list;
	t_gn			*str;

	res = (char *)malloc(BUFF_SIZE + 1);
	ft_bzero(res, BUFF_SIZE + 1);
	if (fd < 0 || read(fd, res, 0) != 0 || \
		BUFF_SIZE < 1 || BUFF_SIZE > 65534)
		return (-1);
	str = correct_struct(&list, fd);
	if (correct_s(&str, line))
		return (1);
	while (read(fd, res, BUFF_SIZE))
	{
		if (ft_strchr(res, '\n'))
			return (write_s(res, &str, line));
		rewrite(&str, res);
		ft_bzero(res, BUFF_SIZE + 1);
	}
	free(res);
	if (!(str->str))
		return (0);
	doddddd_gnl(&str, line);
	return (1);
}
