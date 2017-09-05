/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:01:56 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/11 18:01:56 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		return_hex_shit(char c)
{
	int		i;

	i = 0;
	while (HEX[i] != c)
		i++;
	return (i);
}

void	write_char_file(char *str, int fd)
{
	int				i;
	signed	char	h;

	while (*str && *(str + 1))
	{
		i = return_hex_shit(*str) * 16 + return_hex_shit(*(str + 1));
		h = (signed char)i;
		write(fd, &h, 1);
		str++;
		str++;
	}
}

void	write_command(t_command *com, t_char *lst, int fd)
{
	char	*tmp;
	int		i;

	tmp = ten_hex(com->opcode, NULL, 2);
	write_char_file(tmp, fd);
	free(tmp);
	if (lst->op[com->opcode - 1].octage)
	{
		tmp = codage_octal(com, lst);
		write_char_file(tmp, fd);
		free(tmp);
	}
	i = -1;
	while (++i < com->num_param)
	{
		write_char_file(com->param[i], fd);
		if (com->param[i])
			free(com->param[i]);
	}
}

void	write_byte_code(int fd, t_char *lst, t_label *ll)
{
	t_command	*com;
	t_label		*l;

	l = ll;
	while (l)
	{
		com = l->command;
		while (com && com->opcode != -1)
		{
			write_command(com, lst, fd);
			free(com->param);
			l->command = com->next;
			free(com);
			com = l->command;
		}
		l = l->next;
	}
}

void	write_in_file(int fd, t_char *lst, t_label *l, char *name)
{
	int		i;
	char	*size;

	i = 0;
	write_char_file("00ea83f3", fd);
	i = ft_strlen(lst->name);
	i /= 2;
	i = 128 - i;
	write_char_file(lst->name, fd);
	while (--i >= 0)
		write_char_file("00", fd);
	size = ten_hex(lst->size, NULL, 16);
	write_char_file(size, fd);
	free(size);
	write_char_file(lst->comment, fd);
	i = ft_strlen(lst->comment);
	i /= 2;
	i = 2052 - i;
	while (--i >= 0)
		write_char_file("00", fd);
	write_byte_code(fd, lst, l);
	printf("Write file in %s\n", name);
}
