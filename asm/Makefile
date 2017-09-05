ASM = asm

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

HASM = ./asm.h

FILE = 	./src/asm_main.o \
		./src/correct_char_name.o \
		./src/ten_hex.o \
		./src/label_this.o \
		./src/have_something_after_space.o \
		./src/correct_name_command.o \
		./src/op.o\
		./src/valid_label.o \
		./src/byte_go.o \
		./src/read_while_empty.o\
		./src/codage_octal.o \
		./src/weight_command.o\
		./src/parameter_validation.o\
		./src/arguments_check.o\
		./src/write_in_file.o \
		./src/instead_label_way.o \
		./src/prog_size.o \
		./src/write_char_hex.o \
		./src/open_file_cor.o\
		./src/return_new_command.o \
		./src/start_label.o \
		./src/write_label_name.o \
		./src/cal.o \
		./src/for_par_vad.o \
		./src/free_all.o

OBJ = $(FILE:.o=.c)

all: liba comp 

liba:
	@make -C $(LIBFT)

comp:
	@$(CC) $(FLAGS) $(OBJ) ./libft/libft.a  -o $(ASM)

clean:
	@make clean -C $(LIBFT)

fclean:
	@-/bin/rm -f $(ASM)
	@make fclean -C $(LIBFT)

re: fclean all