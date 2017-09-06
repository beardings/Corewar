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

# include "op.h"
# include "../../libft/header/libft.h"
# include <limits.h>
# include <stdio.h>
# define RED "\x1b[31m"
# define END "\033[0m"

typedef struct			s_players
{
	header_t			*header;
	unsigned char		*comands;
    int                 num;
	int					live;
	int					live_amount;
	char				*comment;
	struct s_players	*next;
}						t_players;

typedef struct			s_flags
{
	int 				visual;
	int					dump;
	int					amount_players;
	int					amount_num;
}						t_flags;

void					print_comands(void);
int						get_flags(t_flags *flags, char **argv);
void					print_error(char *str);
t_flags					*create_flags(void);
int						get_players(t_players *players, char **argv, int argc, t_flags *flags);
t_players 				*create_players(void);
int						is_digit(char *str);

#endif
