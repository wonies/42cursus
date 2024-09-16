# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonhshin <wonhshin@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:52:13 by wonhshin          #+#    #+#              #
#    Updated: 2023/06/14 15:57:29 by wonhshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER	=	mandatory/so_long.h

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS = ./mandatory/so_long.c \
	./mandatory/check_bfs.c \
	./mandatory/check_validate.c \
	./mandatory/error.c \
	./mandatory/find_x.c \
	./mandatory/init.c \
	./mandatory/initialize.c \
	./mandatory/key_check.c \
	./mandatory/key_hook.c \
	./mandatory/lst.c \
	./mandatory/open_file.c \
	./mandatory/put_img.c \
	./mandatory/setting.c \
	./mandatory/get_next_line.c \
	./mandatory/get_next_line_utils.c

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I. $(MLX)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re