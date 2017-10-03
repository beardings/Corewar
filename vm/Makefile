#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:59:21 by mponomar          #+#    #+#              #
#    Updated: 2017/07/04 15:52:53 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar

CC = gcc
FLAGS = -Wall -Wextra -Werror

CONT = controller/
INC = includes/
LIBFT = ../../libft/
FT_INC = $(LIBFT)/includes

COR_CONT =	main.o \
            get_flags.o \

all: $(NAME)

$(NAME): $(COR_CMP)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) -L $(LIBFT) -lft $(COR_CMP)
	@echo "made" $(NAME)

$(COR_CMP): %.o: $(SRC)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(COR_CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out
	rm .*
	rm ._*