/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:25:38 by ngulya            #+#    #+#             */
/*   Updated: 2017/02/09 17:58:57 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef struct		s_gn
{
	char			*str;
	int				fd;
	struct s_gn		*next;
}					t_gn;

int					get_next_line(const int fd, char **line);
void				doddddd_gnl(t_gn **str, char **line);

#endif
