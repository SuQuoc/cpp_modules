NAME		= a.out

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -MMD -MP -std=c++98

SRC_PATH 	= .
OBJ_PATH 	= obj

HDR			= 	Bureaucrat.hpp Form.hpp

SRCS		= 	main.cpp \
				Bureaucrat.cpp \
				Form.cpp


OBJS      = $(SRCS:%.cpp=$(OBJ_PATH)/%.o)

.PHONY: all clean fclean re run va

#Build________________________________________________________
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/tester

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable \"$(NAME)\" succesfully created.$(NC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HDR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@


#General________________________________________________________
clean:
	rm -rf $(OBJ_PATH)
	@echo "$(MAGENTA)Obj directory removed.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "$(MAGENTA)Deleted executable named: $(NAME)$(NC)"

re: fclean all
	@echo "$(GREEN)Recompilation successfully done!$(NC)"

#ADD ONS_______________________________________________________
run: all
	./$(NAME)

va: all
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	./$(NAME)

#COLORS_____________________________________________________________
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE 		=	\033[0;34m
MAGENTA 	=	\033[0;35m
CYAN 		=	\033[0;36m
WHITE		=	\033[0;37m
NC			=	\033[0m
#BOLD COLORS________________________________________________________
BRED		=	\033[1;31m
BGREEN		=	\033[1;32m
BYELLOW		=	\033[1;33m
BBLUE 		=	\033[1;34m
BMAGENTA 	=	\033[1;35m
BCYAN 		=	\033[1;36m
BWHITE		=	\033[1;37m
