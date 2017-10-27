/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:08:01 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/10 16:46:52 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (size + 1));
	return (result);
}
