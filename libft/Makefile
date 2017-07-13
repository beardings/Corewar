#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 15:19:41 by mponomar          #+#    #+#              #
#    Updated: 2017/05/15 15:50:32 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

INC = ./includes
LIB = ./libft
GNL = ./get_next_line
PRINTF = ./ft_printf

LIB_CMP = ft_isascii.o \
		ft_isdigit.o \
		ft_isalpha.o \
		ft_isalnum.o \
		ft_isprint.o \
		ft_strlen.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_strdup.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strncat.o \
		ft_strcat.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strlcat.o \
		ft_atoi.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_memset.o \
		ft_memccpy.o \
		ft_bzero.o \
		ft_memchr.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putnbr.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_putendl.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_strsub.o \
		ft_strjoin.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_itoa.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lenint.o \
		ft_signint.o \
		ft_newsize.o \
		ft_hz.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_spacetrim.o

GNL_CMP = get_next_line.o

PRINTF_CMP = ft_printf.o \
		do_format.o \
		ft_itoa_base.o \
		castflag_s.o \
		castpress_s.o \
		castflag_c.o \
		ft_putstrnew.o \
		writewidth.o \
		writezero.o \
		upperarg.o \
		printhesh.o \
		ft_null.o \
		writewchar_t.o \
		castflag_bigs.o \
		writepress.o \
		dowchar_t.o \
		castpress_bigs.o \
		otherutf.o \
		checkcan.o \
		cast_mod.o \
		cast_standart_for_base.o \
		preox.o \
		cast_mod_base.o \
		base.o \
		minusmissing.o \
		minuspresent.o \
		numnull.o \
		cast_nnnnn.o \
		createres.o \
		startformat.o \
		searcharg.o \
		utflen.o \
		checktype.o \
		cast_mod_cont.o \
		cast_mod_b.o \
		cast_mod_contn.o \
		cast_modnex.o \
		cast_mod_next.o \
		cast_mod_contnext.o \
		castflag_bigc.o

COMPILED = $(LIB_CMP) $(PRINTF_CMP) $(GNL_CMP)

all: $(NAME)

$(NAME): $(COMPILED)
		@ar rc $(NAME) $(COMPILED)
		@ranlib $(NAME)
		@echo "made" $(NAME)

$(LIB_CMP): %.o: $(LIB)/%.c
	@$(CC) -c $(FLAGS) -I $(INC) $< -o $@

$(PRINTF_CMP): %.o: $(PRINTF)/%.c
	@$(CC) -c $(FLAGS) -I $(INC) $< -o $@

$(GNL_CMP): %.o: $(GNL)/%.c
	@$(CC) -c $(FLAGS) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out