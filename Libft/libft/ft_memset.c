/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:28:22 by mponomar          #+#    #+#             */
/*   Updated: 2016/11/30 18:19:20 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = 0;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (ptr);
}
