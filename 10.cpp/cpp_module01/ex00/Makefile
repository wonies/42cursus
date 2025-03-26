NAME	=	Zombie
CC		=	c++ 
CFLAG	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf
SRCS	=	srcs/main.cpp \
			srcs/newZombie.cpp \
			srcs/randomChump.cpp \
			srcs/Zombie.cpp

OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@echo "---------------------------"
	@echo "|                         |"
	@echo "|           🧟            |"
	@echo "|                         |"
	@echo "---------------------------"
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re