#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 16:38:37 by mponomar          #+#    #+#              #
#    Updated: 2017/10/09 19:51:47 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_C = corewar
NAME_A = asm

CC = gcc
FLAGS = -Wall -Wextra -Werror
CURS = -lncurses

ASM = Asm/src/
VM = Vm/src/
INC_VM = Vm/includes/
INC_ASM = Asm/includes/
LIBFT = Libft/
FT_INC = $(LIBFT)/header/

VM_CMP =	main.o \
            get_flags.o \
			get_players.o \
			create_fun.o \
			print_func.o \
			help_func.o \
			change_first_reg.o \
			check_flags_for.o \
			increfvis_getcol_refcurs.o \
			lives_rightbar_inccol.o \
			hex_board_printbo_prrcnext.o \
			print_new_map.o \
			go_vm_vis.o \
			print_row.o \
			start_vm.o \
			print_rc.o \
			funcs.o \
			test_oppcode.o \
			for_func.o \
			funcs_ld.o \
			for_funcs_ld_norm.o \
			for_func_ld_norm_sec.o \
			funcs_math.o \
			power.o \
			livas_base.o \
			go.o \
			funcs_forks.o \
			funcs_st.o \
			go_head.o \
			go_middle.o \
			go_center.o \
			go_down.o 

ASM_CMP =	asm_main.o \
			correct_char_name.o \
			ten_hex.o \
			label_this.o \
			have_something_after_space.o \
			correct_name_command.o \
			op.o \
			norm_main.o \
			valid_label.o \
			byte_go.o \
			read_while_empty.o \
			codage_octal.o \
			weight_command.o \
			parameter_validation.o \
			arguments_check.o \
			write_in_file.o \
			instead_label_way.o \
			prog_size.o \
			write_char_hex.o \
			open_file_cor.o \
			return_new_command.o \
			start_label.o \
			write_label_name.o \
			cal.o \
			for_par_vad.o \
			free_all.o \
			most_long_long.o 


all: $(NAME_C) $(NAME_A)

$(NAME_C): $(VM_CMP)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_C) -L $(LIBFT) -lft $(VM_CMP) $(CURS)
	@echo "made" $(NAME_C)

$(NAME_A): $(ASM_CMP)
	@$(CC) $(FLAGS) -o $(NAME_A) -L $(LIBFT) -lft $(ASM_CMP)
	@echo "made" $(NAME_A)

$(VM_CMP): %.o: $(VM)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC_VM) $< -o $@

$(ASM_CMP): %.o: $(ASM)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC_ASM) $< -o $@

clean:
	@-/bin/rm -f $(VM_CMP)
	@-/bin/rm -f $(ASM_CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME_C)
	@echo "cleaned" $(NAME_A)

fclean: clean
	@-/bin/rm -f $(NAME_C)
	@-/bin/rm -f $(NAME_A)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME_C)
	@echo "fcleaned" $(NAME_A)

re: fclean all

rmf:
	rm *~
	rm ._*