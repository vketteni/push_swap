NAME = push_swap
SRCS = push_swap.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	swap.c \
	ft_divide_upto_median.c \
	ft_get_median.c \
	ft_initialize_stack.c \
	ft_sort_and_print.c \
	ft_merge.c \
	ft_execute_rr_merge.c \
	ft_execute_ra_rrb_merge.c \
	ft_execute_rrr_merge.c \
	ft_execute_rra_rb_merge.c \
	ft_sort_simultaneous.c \
	ft_execute_queue.c \
	ft_next_operation_a.c \
	ft_next_operation_b.c \
	ft_get_next.c \
	initialize_sorted_sublists.c \
	relations.c \
	distances.c \
	ft_distance_between.c \
	sorted.c \
	ft_absolute.c \


OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Wextra -Werror -g
vpath %.c sorting sorting/merge sorting/sort_simultaneous sorting/divide_upto_median instructions utils
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