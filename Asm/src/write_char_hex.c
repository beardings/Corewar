/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:51:35 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/21 14:51:36 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	write_char_hex(char *line, t_char *lst, int i)
{
	if (i == 1)
	{
		while (*line && *line != '"')
			line++;
		line++;
		while (*line && *line != '"')
		{
			lst->name = ten_hex(*line, lst->name, 2);
			line++;
		}
	}
	if (i == 2)
	{
		while (*line && *line != '"')
			line++;
		line++;
		while (*line && *line != '"')
		{
			lst->comment = ten_hex(*line, lst->comment, 2);
			line++;
		}
	}
}
