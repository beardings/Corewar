/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_cor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:50:38 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 14:50:39 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		open_file_cor(char *name, int fd)
{
	int		fd2;

	fd2 = open(name, O_TRUNC);
	if (fd2 == -1)
		fd2 = open(name, O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
	else
	{
		close(fd2);
		fd2 = open(name, S_IRUSR | S_IWUSR | O_RDWR);
	}
	if (fd2 == -1)
	{
		close(fd);
		printf("Error: couldn't create file, maybe you need chmod\n");
		return (0);
	}
	return (fd2);
}
