CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = aide.c atoi.c aide_struct.c parssing.c ra_sa_pa_rra.c sort.c split.c push_swap.c main.c


NAME = push_swap
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@



%.o : %.c  push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all