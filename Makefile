NAME = push_swap
SRCS = source/instructions/push.c \
	source/instructions/reverse_rotate.c \
	source/instructions/rotate.c \
	source/instructions/swap.c \
	source/sort_five_or_four.c \
	source/sort_three.c \
	source/sort_gt_five.c \
	source/initialize.c \
	utils/util1.c \
	utils/util2.c \
	utils/util3.c \
	push_swap.c \

OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror -g


all: ${NAME} 

${NAME}: ${OBJS} libft ft_printf
	${CC} ${FLAGS} ${OBJS} -Lsubmodules/libft -lft -Lsubmodules/ft_printf -lftprintf -o ${NAME}

%.o: %.c 
	${CC} ${FLAGS} -Isubmodules/libft -Isubmodules/ft_printf -c $? -o $@

libft:
	${MAKE} -C submodules/libft

ft_printf:
	${MAKE} -C submodules/ft_printf

clean:
	${MAKE} clean -C submodules/libft
	${MAKE} clean -C submodules/ft_printf
	rm -f ${OBJS}

fclean: clean
	${MAKE} fclean -C submodules/libft
	${MAKE} fclean -C submodules/ft_printf
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re