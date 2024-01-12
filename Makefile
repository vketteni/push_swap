NAME = push_swap
SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror -Iincludes
%.o: %.c
	@${CC} ${FLAGS} -Ilibft -Ift_printf -c $? -o $@
all: ${NAME}

NAME: ${OBJS}
	@${MAKE} -C libft
	@${MAKE} -C ft_printf
	@${CC} ${FLAGS} ${OBJS} -Llibft -llibft -Lft_printf -lft_printf -o ${NAME}

LIBFT:
	@${MAKE} -C libft

FT_PRINTF:
	@${MAKE} -C ft_printf

clean:
	@${MAKE} clean -C ./libft
	@${MAKE} clean -C ./ft_printf
	@rm -f ${OBJS}

fclean: clean
	@${MAKE} fclean -C ./libft
	@${MAKE} fclean -C ./ft_printf
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re