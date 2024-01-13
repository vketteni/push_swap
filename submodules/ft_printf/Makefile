SRCS = ft_printf.c \
	ft_decimal_to_base.c \
	ft_base_to_decimal.c \
	ft_print_format_string.c \
	ft_print_dec.c \
	ft_print_ptr.c \
	ft_print_str.c \
	ft_print_char.c \
	ft_print_hex.c \

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
all: $(NAME)

clean:
	rm -Rf $(OBJS)
fclean:	clean
	rm -Rf $(NAME)
re: fclean all
