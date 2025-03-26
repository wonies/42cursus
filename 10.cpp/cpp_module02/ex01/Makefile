NAME	=	Fixed_Point
CXX = c++
RM = rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = -I Inc

SRC_DIR = srcs
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@echo "---------------------------"
	@echo "|                         |"
	@echo "|       Fixed_Point       |"
	@echo "|                         |"
	@echo "---------------------------"
	@$(CXX) $(CXXFLAGS) $^ -o $(NAME)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all