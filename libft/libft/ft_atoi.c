/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:11:04 by mponomar          #+#    #+#             */
/*   Updated: 2016/12/08 21:48:51 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '\200')
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	return (result * sign);
}
