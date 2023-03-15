NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

M_SRCS = ft_printf.c \
	check.c \
	ft_function.c \
	ft_puts.c \
	ft_putdeci.c\
	ft_pointer.c\
	ft_hex.c\

M_OBJS = $(M_SRCS:%.c=%.o)

OBJS = $(M_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I .

clean:
	$(RM) $(M_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re