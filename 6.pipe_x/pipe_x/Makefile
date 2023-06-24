NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	pipex.h
BONUS_HEADER = pipex.h

SRCS = mandatory/pipex.c \
	mandatory/child.c \
	mandatory/close.c \
	mandatory/error.c \
	mandatory/find_path.c \
	mandatory/init.c \
	mandatory/split.c \
	mandatory/utils.c
	

BONUS_SRCS = 	bonus/pipex_bonus.c \
	bonus/child_bonus.c \
	bonus/close_bonus.c \
	bonus/error_bonus.c \
	bonus/find_path_bonus.c \
	bonus/heredoc_bonus.c \
	bonus/init_bonus.c \
	bonus/pipe_bonus.c \
	bonus/set_path_bonus.c \
	bonus/split_bonus.c \
	bonus/utils_bonus.c \
	bonus/gnl/get_next_line.c \
	bonus/gnl/get_next_line_utils.c

M_OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS)
	HEADER = bonus/pipex_bonus.h
else
	OBJS = $(M_OBJS)
	HEADER = mandatory/pipex.h
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:
	@$(RM) ./mandatory/*.o	
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