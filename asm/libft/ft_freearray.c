/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 22:25:36 by ybelilov          #+#    #+#             */
/*   Updated: 2017/07/04 22:25:41 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(char **array)
{
	int i;

	i = -1;
	while (array[++i])
		ft_memdel((void**)&array[i]);
	ft_memdel((void**)&array);
}
