/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:39:18 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/17 15:03:22 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"
#include "../header/libft.h"

static char			*ft_charplus(char const *s1, char c)
{
	char		*str;
	size_t		count;
	size_t		length;

	if (s1 == NULL || !c)
		return (NULL);
	length = ft_strlen(s1);
	if ((str = ft_strnew(length + 1)) == NULL)
		return (NULL);
	count = 0;
	while (count < length)
	{
		*(str + count) = *(s1 + count);
		count++;
	}
	*(str + count) = c;
	return (str);
}

static int			ft_copy(char **dst, char *src, char c)
{
	int		one;
	int		two;
	int		point;
	char	*str;

	one = -1;
	two = -1;
	while (src[++one])
		if (src[one] == c)
			break ;
	point = one;
	if (*dst)
		free(*dst);
	if (!(*dst = ft_strnew(one)))
		return (0);
	str = *dst;
	while (src[++two] && two < one)
	{
		if (!(*dst = ft_charplus(*dst, src[two])))
			return (0);
		if (str)
			free(str);
		str = *dst;
	}
	return (point);
}

static int			gnl(char *current[4096][3], char buffer[], const int fd)
{
	size_t		buf;

	buf = 0;
	while ((buf = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[buf] = '\0';
		if (current[fd][0] == NULL)
		{
			if (current[fd][1])
				free(current[fd][1]);
			current[fd][0] = ft_strnew(ft_strlen(buffer));
			current[fd][1] = current[fd][0];
		}
		if (!(current[fd][0] = ft_strjoin(current[fd][0], buffer)))
			return (-1);
		if (current[fd][2])
			free(current[fd][2]);
		current[fd][2] = current[fd][0];
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (buf < BUFF_SIZE && !ft_strlen(current[fd][0]))
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static	char	*file[4096][3];
	int				flag;
	int				ret;

	flag = 0;
	if ((fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
			|| !(*line = ft_strnew(1)))
		return (-1);
	if (!file[fd][0])
	{
		file[fd][0] = NULL;
		file[fd][1] = NULL;
		file[fd][2] = NULL;
	}
	ret = gnl(file, buffer, fd);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	((flag = ft_copy(line, file[fd][0], '\n')) < (int)ft_strlen(file[fd][0])) ?
		file[fd][0] += (flag + 1)
		: ft_strclr(file[fd][0]);
	return (1);
}
