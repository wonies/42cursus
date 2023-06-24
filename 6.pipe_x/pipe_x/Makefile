NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	pipex.h
BONUS_HEADER = pipex.h

SRCS = pipex.c \
	path.c \
	path2.c \
	error.c \
	init.c \
	init2.c \
	split.c \
	free_all.c
	
BONUS_SRCS = 	bonus/pipex_bonus.c \
	bonus/init_bonus.c \
	bonus/pipex_gnl.c \
	bonus/get_next_line.c \
	bonus/get_next_line_utils.c \
	path.c \
	path2.c \
	error.c \
	init.c \
	init2.c \
	split.c \
	free_all.c

M_OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS)
	HEADER = pipex.h
else
	OBJS = $(M_OBJS)
	HEADER = pipex.h
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:
	@$(RM) ./*.o	
	@make WITH_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(M_OBJS)
	$(RM) $(B_OBJS)

fclean: 
	make clean
	$(RM) $(NAME)

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re bonus