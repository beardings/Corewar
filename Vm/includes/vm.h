/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:10:54 by mponomar          #+#    #+#             */
/*   Updated: 2017/10/03 18:55:34 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../../Libft/header/libft.h"
# include <limits.h>
# include <stdio.h>
# include <ncurses.h>
# include <fcntl.h>
# include <unistd.h>
# define RED "\x1b[31m"
# define END "\033[0m"
# define HEX "0123456789abcdef"
# define MAP_SIZE (MEM_SIZE - 1)

typedef	unsigned char 		byte;
typedef	int					t_bool;
typedef struct s_players 	t_players;

typedef struct          s_op
{
    char                name[20];
    int                 arguments;
    int                 r_d_i[10];
    int                 number;
    int                 cycles;
    char                desriptions[200];
    int                 octage;
    int                 carry;
    int                 label_size;
}                       t_op;

struct					s_players
{
	t_header			header;
	char				*comands;
	int					live;
	int					live_amount;
	int					num;
	int 				pos;
	unsigned int		*reg;
	int					stop;
	int					carry;
	int					*cycles;
	int					curr_com;
	int					*last_herro;
	int					last_live;
	int					st;
	int					number;
	t_players			*next;
};

typedef struct			s_flags
{
	int 				visual;
	int					dump;
	int					amount_players;
	int					amount_num;
	int					paused;
	int					process;
	int					speed;
	int					base;
	int					cycles;
	int					DIE;
	int					cycles_test;
	int					max_checks;
	byte				*map_color;
}						t_flags;

void					print_comands(void);
void					print_data_players(t_players **players);
void					print_error(char *str);
int						get_flags(t_flags *flags, char **argv);
int						get_players(t_players *players,
									char **argv, int argc, t_flags *flags);
int						is_digit(char *str);
t_flags					*create_flags(void);
t_players				*create_players(void);
long long int			ft_atoilong(const char *str);
int						ft_swap_players(t_players **players,
										int amount_players);
char					*ten_hex(int i, char *str, int size);
unsigned int			change_bite(unsigned int num);
int						ft_swap_players(t_players **players,
										int amount_players);
void					change_first_reg_players(t_players **players);
int						check_amount(t_flags *flags);
int						check_flags_for_players(int argc,
												t_flags *flags, char **argv);
int						sort_list(t_players **head, t_flags *flags);
void					zjmp(t_players *player, byte *map);
void					live(t_players *players, byte *map, t_players *player);
void					sti(t_players *player, byte *map);
void					and_xor(t_players *player, byte *map, char flag);
char					*get_binary(byte *map, t_players *player);
void					ld(t_players *player, byte *map);
void					st(t_players *player, byte *map);
void					add(t_players *player, byte *map);
void					sub(t_players *player, byte *map);
void					ldi(t_players *player, byte *map);
void					lldi(t_players *player, byte *map);
void					lld(t_players *player, byte *map);
void					fork_func(t_players *player, byte *map, t_players **stack);
void					lfork_func(t_players *player, byte *map, t_players **stack);
void					aff(t_players *player, byte *map);
void					start_vm(t_players **tmp, int count, t_flags *flags);
void					get_stop(t_players *player, byte *map);
int 					translate(byte r1, byte r2, byte r3, byte r4);
int						get_TDIR(int n, int posit, byte *map);
int						get_REG(t_players *player, int posit, byte *map);
int						get_INDIR(t_players *player, char flag, int posit, byte *map);
int						check_oppcode(t_players *player, byte *map);
int						check_reg(int posit, byte *map);
char 					*livas_base(long long int n, int base);
int						power(int number, int power);
void					main_cycle(t_players *players, byte *map, t_players **stack, t_flags *flags);
void					check_all(t_players *players, byte *map, t_players **stack, t_flags *flags);
char 					*for_blyalld(int *r1, int *posit, t_players *player, byte *map);
void					for_ld_end(byte *map, t_players **player, int posit, int r1);
void					mu_obnylyaem(int *r1, int *r2, int *for_r, int *posit);
int						for_ldi_peredstart(t_players **p, int *posit, byte *map, char **bin);
int						for_ldi_start(t_players **player, int *posit, byte *map, char **bin);
int						return_ldi(byte *map, t_players *player, int *posit);
int						lldi_hahamf_norm(t_players **player, int *posit, byte *map, char **b);
void					and_xor_part2(char *opp, t_players *player, byte *map, int **args);
void					and_xor_part3(char *opp, t_players *player, byte *map, int **args);
void					and_xor_part4(char flag, t_players *player, byte *map, int **args);
void					main_cycle(t_players *players, byte *map, t_players **stack, t_flags *flags);
void					go_vm(t_players *players, int count, t_flags *flags);
void					get_stop(t_players *player, byte *map);
byte					*get_map(t_players *players, int count, int *cycles);
void					check_all(t_players *players, byte *map, t_players **stack, t_flags *flags);
void					get_command(t_players *player, byte *map, t_players **stack,
									t_players *players);
void					get_map_dop(byte *map, char **ptr, int i);
int 					get_last(t_players *players);
int 					get_alive_players(t_players *players);
void					check_carry(t_players *player, int r1, int r2, char flag);
void					get_color(t_players *players, t_players **stack, t_flags *flags);
void					refresh_cursor(t_players *players, t_flags *flags, t_players *stack, byte *map);
void					include_refresh_vis(t_players *players, t_flags *flags, t_players *stack, byte *map);
void					print_board(void);
void    				board_kay(t_flags *flags);
void 					players_right_bar(t_players *players);
void					print_new_map(byte *map, byte *map_color);
void					lives_right_row(t_players *players, int DIE, int y);
void					right_bar(t_flags *flags, t_players *players, t_players *stack);
void					print_row(t_players *players, int point, int y);
int     				size_processes(t_players **stack);
void					include_beginer_vis(void);
void 					print_rc_end(int skiko, int color, int pos, int y);
int 					print_rc_next(int *did);
char					*get_hex(byte val);
void					print_rc(int all, int size, int *did, int y);
void					go_vm_vis(t_players *players, int count, t_flags *flags);
byte					*get_map_color(t_players *players, int count, int *cycles);
void					get_command(t_players *player, byte *map, t_players **stack, t_players *players);
byte					*get_map(t_players *players, int count, int *cycles);
void					end_game(t_players *players, byte *map, t_players **stack, t_flags *flags);
int 					get_lives(t_players *players, t_players *stack);
void					check_end(t_players *players, byte *map, t_players **stack, t_flags *flags);
void					print_row(t_players *players, int point, int y);
void					go_vm(t_players *players, int count, t_flags *flags);
int     				find_i(int *i, int *did, int skiko, int all);
void	suka_suma(byte **map, t_players **player, int r12, int r3);
void	suka_suma_dva(byte **map, t_players **player, int r12, int r3);
void			rename_players(t_players *player);
void			insert_sorted(t_players **head, t_players *new_node);


#endif
