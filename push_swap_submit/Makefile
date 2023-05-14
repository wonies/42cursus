NAME = push_swap
BONUS_NAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	mandatory/push_swap.h
BONUS_HEADER = bonus/push_swap_bonus.h

SRCS = mandatory/main.c \
	mandatory/check.c \
	mandatory/error.c \
	mandatory/getting.c \
	mandatory/init.c \
	mandatory/lst.c \
	mandatory/order1.c \
	mandatory/order2.c \
	mandatory/order3.c \
	mandatory/parsing.c \
	mandatory/sort_a.c \
	mandatory/sort_b.c \
	mandatory/start.c \
	mandatory/ft_atoi.c \
	mandatory/ft_split.c \
	mandatory/handmade.c \

BONUS_SRCS = 	bonus/bonus_main.c \
	bonus/get_next_line_utils.c \
	bonus/get_next_line.c \
	bonus/bonus_init.c \
	bonus/read_gnl.c \
	mandatory/order1.c \
	mandatory/order2.c \
	mandatory/order3.c \
	mandatory/check.c \
	mandatory/error.c \
	mandatory/parsing.c \
	mandatory/ft_atoi.c \
	mandatory/ft_split.c \
	mandatory/init.c \
	mandatory/lst.c \

OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	$(BONUS_NAME)
$(BONUS_NAME):	$(BONUS_OBJS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: 
	make clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re bonus