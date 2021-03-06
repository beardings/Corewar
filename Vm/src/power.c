/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:39:12 by liabanzh          #+#    #+#             */
/*   Updated: 2017/10/28 01:03:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int				power(int number, int power)
{
	int			res;

	res = number;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= number;
		power--;
	}
	return (res);
}

void			insert_sorted(t_players **head, t_players *new_node)
{
	t_players	*tmp_node;

	tmp_node = NULL;
	if (*head == NULL || new_node->num < (*head)->num)
	{
		new_node->next = *head;
		*head = new_node;
		return ;
	}
	tmp_node = *head;
	while (tmp_node->next && new_node->num > tmp_node->next->num)
	{
		tmp_node = tmp_node->next;
	}
	new_node->next = tmp_node->next;
	tmp_node->next = new_node;
}

void			rename_players(t_players *player)
{
	int			i;

	i = 1;
	while (player)
	{
		player->num = i;
		i++;
		player = player->next;
	}
}
