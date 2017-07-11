/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:10:54 by mponomar          #+#    #+#             */
/*   Updated: 2017/07/08 17:12:39 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../libft/header/libft.h"
# include <limits.h>
# include <stdio.h>
# define RED "\x1b[31m"
# define END "\033[0m"

typedef struct		s_player
{
	int 			x;
}					t_player;

typedef struct		s_flags
{
	int 			visual;
	int				dump;
}					t_flags;

void	print_comands(void);
int		get_flags(t_flags *flags, char **argv);
void	print_error(char *str);

#endif
