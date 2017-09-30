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
	header_t			header;
	unsigned char		*comands;
    int                 num;
	int					live;
	int					live_amount;
	int                 pos;
	unsigned int        *reg;
	int                 stop;
	int                 carry;
	int                 *live_ptr;
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
void					print_data_players(t_players **players);
void					print_error(char *str);
int						get_flags(t_flags *flags, char **argv);
int						get_players(t_players *players, char **argv, int argc, t_flags *flags);
int						is_digit(char *str);
t_flags					*create_flags(void);
t_players 				*create_players(void);
long long int			ft_atoiLong(const char *str);
int                     ft_swap_players(t_players **players, int amount_players);

#endif
