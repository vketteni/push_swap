NAME = push_swap
SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror 

%.o: %.c 
	${CC} ${FLAGS} -Isubmodules/libft -Isubmodules/ft_printf -c $? -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C submodules/libft bonus
	@${MAKE} -C submodules/ft_printf
	@${CC} ${FLAGS} ${OBJS} -Lsubmodules/libft -lft -Lsubmodules/ft_printf -lftprintf -o ${NAME}

clean:
	@${MAKE} clean -C submodules/libft
	@${MAKE} clean -C submodules/ft_printf
	@rm -f ${OBJS}

fclean: clean
	@${MAKE} fclean -C submodules/libft
	@${MAKE} fclean -C submodules/ft_printf
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re