/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:56:33 by ngulya            #+#    #+#             */
/*   Updated: 2017/07/05 13:56:33 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdio.h>
# include "../../Libft/header/libft.h"

# define HEX "0123456789abcdef"
# define OP main->op
# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE 4
# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3
# define MAX_ARGS_NUMBER 4
# define MAX_PLAYERS 4
# define MEM_SIZE (4*1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)
# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR	 ','
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_NUMBER 16
# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10
# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct			s_op
{
	char				name[20];
	int					arguments;
	int					r_d_i[10];
	int					number;
	int					cycles;
	char				desriptions[200];
	int					carry;
	int					octage;
	int					label_size;
}						t_op;

typedef struct			s_command
{
	int					opcode;
	int					num_param;
	int					param_type[3];
	char				**param;
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char				*name;
	t_command			*command;
	struct s_label		*next;
}						t_label;

typedef struct			s_char
{
	char				*name;
	char				*comment;
	int					fd;
	int					size;
	t_op				*op;
}						t_char;

typedef struct			s_cal
{
	t_label				*lbl;
	char				*str;
	int					size;
	char				*tmp;
}						t_cal;

int						correct_end_s(char *s);
int						go_to_znak(char **line, int j);
int						correct_char_name(char \
						**str, int size, int fd, int plus);
char					*read_while_empty(char *line, int fd);
char					*ten_hex(long long int i, char *str, int size);
t_label					*byte_go(int fd, t_char *lst);
int						correct_label_char(char *str, int size);
void					get_op(t_char **lst);
int						have_something_after_space(char *str);
int						label_this(char *line);
int						correct_name_command\
						(char *line, t_char *lst, t_command *s);
int						valid_label(t_label *l);
void					write_in_file(int fd,\
						t_char *lst, t_label *l, char *name);
int						prog_size(t_char *lst, t_label *lbl);
int						instead_label_way(t_label *l, t_char *lst);
char					*codage_octal(t_command *c, t_char *lst);
int						weight_command(t_command *c, t_char *lst);
void					free_char(t_char *lst);
void					free_label(t_label *l);
int						open_file_cor(char *name, int fd);
void					write_char_hex(char *line, t_char *lst, int i);
void					free_all(t_char *lst, t_label *l, char *line);
t_command				*return_new_command(t_label *l, t_command **t);
int						start_label(char **line, t_label *l, t_char *lst);
void					function_for_first_time(t_label **l);
int						cal1(t_label *start,\
						t_command *c, t_char *lst, char *str);
int						cal2(t_label *now, t_command *c, t_char *lst);
int						cal3(t_label *now,\
						t_command *c, t_char *lst, char *str);
int						parameter_validation(t_char\
						*main, t_command *cmd, char *com);
t_label					*write_label_name(t_label *l, char *line);
int						is_t_dir(char *arg, int size, t_command *c, int i);
int						is_t_ind(char *arg, t_command *c, int i);
int						is_t_reg(char *arg, t_command *c, int i);
char					*delete_fuck(char **ls);
char					**ft_array_trim(char **array);
long int				array_len(char **arr);
long long int			most_long_long(char *str);
int						check_for_comment_at_the_end(char *str);
long int				array_len(char **arr);
char					**ft_array_trim(char **array);
#endif
