NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	pipex.h
BONUS_HEADER = pipex.h

SRCS = pipex.c \
	path_parsing.c \
	path_process.c \
	path_process_transp.c \
	freecloseerror.c \
	init.c \
	init_file.c \
	split.c 
	
BONUS_SRCS = 	bonus/pipex_bonus.c \
	bonus/init_bonus.c \
	bonus/get_next_line.c \
	bonus/get_next_line_utils.c \
	path_parsing.c \
	path_process.c \
	path_process_transp.c \
	freecloseerror.c \
	init.c \
	init_file.c \
	split.c 

M_OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS)
else
	OBJS = $(M_OBJS)
endif

all :
	$(RM) ./bonus/*.o
	$(MAKE) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:
	@$(RM) ./pipex.o
	@make WITH_BONUS=1 $(NAME)

clean:
	# $(RM) $(OBJS)
	$(RM) $(M_OBJS)
	$(RM) $(B_OBJS)
	
fclean: 
	make clean
	$(RM) $(NAME)

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re bonus