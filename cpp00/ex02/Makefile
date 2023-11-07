NAME		= booking

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98

SRC_PATH 	= .
OBJ_PATH 	= obj

HDR 		= Account.hpp
SRC			= tests.cpp \
				Account.cpp

OBJ 		= $(SRC:.cpp=.o)

.PHONY: all bonus clean fclean re aa va
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "$(GREEN)Executable \"$(NAME)\" succesfully created.$(NC)"

$(OBJ): $(SRC) $(HDR)
	$(CC) -c $(CFLAGS) $(SRC)

#General
##############################################################################
clean:
	rm -rf $(OBJ)
	@echo "$(MAGENTA)Obj directory removed.$(NC)"
	@echo "$(MAGENTA)Make clean in directory "$(LIBFT_DIR)" invoked.$(NC)"

fclean: clean
	rm -f $(NAME)
	@echo "$(MAGENTA)Deleted executable named: $(NAME)$(NC)"
	@echo "$(MAGENTA)Make fclean in directory "$(LIBFT_DIR)" invoked.$(NC)"

re: fclean all
	@echo "$(GREEN)Recompilation successfully done!$(NC)"
##############################################################################

#Some of my extras
##############################################################################
aa: all
	@echo "$(GREEN)Executing programm with \"TEST_INPUT\" of the Makefile.$(NC)"
	./$(NAME) $(ARGV)
	./$(NAME) $(ARGV) > output.txt

va: all
	make -C ./ clean
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		./$(NAME)

debug : CFLAGS += -g
debug : fclean all
##############################################################################




#--------COLORS---------------------------------#
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE 		=	\033[0;34m
MAGENTA 	=	\033[0;35m
CYAN 		=	\033[0;36m
WHITE		=	\033[0;37m
NC			=	\033[0m


#-------BOLD COLORS-----------------------------#
BRED		=	\033[1;31m
BGREEN		=	\033[1;32m
BYELLOW		=	\033[1;33m
BBLUE 		=	\033[1;34m
BMAGENTA 	=	\033[1;35m
BCYAN 		=	\033[1;36m
BWHITE		=	\033[1;37m
