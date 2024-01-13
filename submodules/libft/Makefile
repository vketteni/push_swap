NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

CC = cc 

SRC = ft_tolower.c ft_isdigit.c ft_strlen.c ft_isalnum.c ft_strrchr.c \
ft_strmapi.c ft_memcpy.c ft_strjoin.c ft_strnstr.c ft_isascii.c \
ft_calloc.c ft_substr.c ft_striteri.c ft_itoa.c ft_bzero.c ft_memcmp.c \
ft_strdup.c ft_strncmp.c ft_toupper.c ft_putchar_fd.c ft_isprint.c \
ft_isalpha.c ft_memmove.c ft_strlcat.c ft_strtrim.c ft_putnbr_fd.c \
 ft_atoi.c ft_memchr.c ft_strchr.c ft_strlcpy.c ft_split.c \
ft_putstr_fd.c ft_memset.c ft_putendl_fd.c

SRC_BONUS = ft_lstsize.c ft_lstdelone.c ft_lstnew.c ft_lstiter.c ft_lstclear.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus:  $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o:	%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: re bonus all fclean clean
