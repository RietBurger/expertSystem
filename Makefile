#run with this when checking leaks: valgrind --leak-check=summary -v ./expert < marking/test5.txt 


NAME = expert

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/

INC_DIR = -I inc/

SRCS =	main.c \
	  	read_file.c \
		sort_info.c \
		ft_symbol.c \
		ft_match.c \
		save_given.c \
		ft_undefined.c \
		ft_main_output.c \
		free.c \

		

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

$(NAME):
	$(CC) $(INC_DIR) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	make clean

all : $(NAME)

.PHONY: clean fclean re

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
#	make -C libft/ fclean

re: fclean all

#./filler_vm -p1 players/champely.filler -p2 ../miner.filler -v -f maps/map00
