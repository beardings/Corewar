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

int		correct_end_s(char *s)
{
	while (*s && *(s + 1) && *(s + 2))
		s++;
	if (*s && !ft_strcmp(s, ".s"))
		return (1);
	return (0);
}

int		if_name_comment(int fd, char **line, int i, t_char *lst)
{
	if (i == 1)
		*line = read_while_empty(*line, fd);
	if (i == 1 && *line && !ft_strncmp(*line, NAME_CMD_STRING, 5)\
		&& have_something_after_space(*line + 5) \
		&& correct_char_name(*line + 5, 128))
	{
		write_char_hex(*line + 5, lst, 1);
		free(*line);
		*line = NULL;
		*line = read_while_empty(*line, fd);
		return (1);
	}
	if (i == 2 && *line && !ft_strncmp(*line, COMMENT_CMD_STRING, 8)\
		&& have_something_after_space(*line + 8) \
		&& correct_char_name(*line + 8, 2048))
	{
		write_char_hex(*line + 8, lst, 2);
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
	if (!if_name_comment(fd, &line, 1, lst))
		ft_putstr("Error: bad name\n");
	else if (!if_name_comment(fd, &line, 2, lst))
		ft_putstr("Error: bad comment\n");
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
			ft_putstr("Error\n");
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
		printf("Error: Bad file %s\n", argv);
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
		ft_putstr("./asm filenmae.s\n");
	else if (argc > 5)
		ft_putstr("Only 4 arguments.s\n");
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
