NAME = push_swap
BONUS_NAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	mandatory/push_swap.h
BONUS_HEADER = bonus/push_swap_bonus.h

SRCS = mandatory/ready/push_main.c \
	mandatory/ready/check.c \
	mandatory/ready/start.c \
	mandatory/ready/parsing.c \
	mandatory/error/error.c \
	mandatory/init/init.c \
	mandatory/init/lst.c \
	mandatory/init/ft_atoi.c \
	mandatory/init/ft_split.c \
	mandatory/order/push.c \
	mandatory/order/swap.c \
	mandatory/order/rotate.c \
	mandatory/order/rotate_plus.c \
	mandatory/sort/getting.c \
	mandatory/sort/sort_a.c \
	mandatory/sort/sort_b.c \
	mandatory/sort/min_sort.c \

BONUS_SRCS = 	bonus/bonus_main.c \
	bonus/bonus_init.c \
	bonus/bonus_start.c \
	bonus/gnl/get_next_line_utils.c \
	bonus/gnl/get_next_line.c \
	mandatory/error/error.c \
	mandatory/order/push.c \
	mandatory/order/swap.c \
	mandatory/order/rotate.c \
	mandatory/order/rotate_plus.c \
	mandatory/ready/check.c \
	mandatory/ready/start.c \
	mandatory/ready/parsing.c \
	mandatory/init/init.c \
	mandatory/init/lst.c \
	mandatory/init/ft_atoi.c \
	mandatory/init/ft_split.c \
	mandatory/sort/getting.c \
	mandatory/sort/min_sort.c \
	mandatory/sort/sort_a.c \
	mandatory/sort/sort_b.c \
	

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