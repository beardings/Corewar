/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_something_after_space.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:57:40 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/10 12:57:41 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		have_something_after_space(char *str)
{
	while (str && *str && (*str == ' ' || *str == '\t'))
		str++;
	return (str && *str && *str != '#' ? 1 : 0);
}
