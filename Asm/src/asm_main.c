/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:52:09 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/05 13:52:09 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		if_name(int fd, char **line, t_char *lst)
{
	int		frst;
	char	*str;

	frst = 0;
	*line = read_while_empty(*line, fd);
	str = *line;
	while (str && *str && (*str == ' ' || *str == '\t'))
	{
		str++;
		frst++;
	}
	if ((*line + frst) && !ft_strncmp((*line + frst), NAME_CMD_STRING, 5)\
		&& have_something_after_space((*line + frst) + 5) \
		&& correct_char_name(line, 128 - 2, fd, frst + 5))
	{
		write_char_hex((*line + frst) + 5, lst, 1);
		free(*line);
		*line = NULL;
		*line = read_while_empty(*line, fd);
		return (1);
	}
	return (0);
}

int		if_comment(int fd, char **line, t_char *lst)
{
	int		frst;
	char	*str;

	frst = 0;
	str = *line;
	while (str && *str && (*str == ' ' || *str == '\t'))
	{
		str++;
		frst++;
	}
	if ((*line + frst) && !ft_strncmp((*line + frst), COMMENT_CMD_STRING, 8)\
		&& have_something_after_space((*line + frst) + 8) \
		&& correct_char_name(line, 2048 - 2, fd, frst + 8))
	{
		write_char_hex((*line + frst) + 8, lst, 2);
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

int		ok_lets_go(int fd, t_char *lst, char *name)
{
	char	*line;
	t_label	*l;
	int		fd2;

	l = NULL;
	line = NULL;
	if (!if_name(fd, &line, lst))
		ft_printf("Error: bad name    %s\n", name);
	else if (!if_comment(fd, &line, lst))
		ft_printf("Error: bad comment    %s\n", name);
	else
	{
		if ((l = byte_go(fd, lst)))
		{
			if ((fd2 = open_file_cor(name, fd)) > 0)
			{
				write_in_file(fd2, lst, l, name);
				close(fd2);
			}
		}
		else
			ft_printf("Error    %s\n", name);
	}
	free_all(lst, l, line);
	return (1);
}

void	start_this(char *argv)
{
	int		fd;
	char	*tmp;
	char	*name;
	t_char	*lst;

	fd = -1;
	if (correct_end_s(argv))
		fd = open(argv, O_RDONLY);
	if (fd <= 0)
		ft_printf("Error: Bad file %s\n", argv);
	else
	{
		tmp = ft_strndup(argv, ft_strlen(argv) - 2);
		name = ft_strjoin(tmp, ".cor");
		free(tmp);
		lst = (t_char *)malloc(sizeof(t_char));
		lst->name = NULL;
		lst->fd = fd;
		lst->comment = NULL;
		get_op(&lst);
		ok_lets_go(fd, lst, name);
		free(name);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_putstr("./asm filename.s\n");
	else
	{
		while (i < argc)
		{
			start_this(argv[i]);
			i++;
		}
	}
	return (0);
}
