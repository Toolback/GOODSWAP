#Variables

NAME		= push_swap
INCLUDE		= -I include/
LIBFT		= libft/
SRC_DIR		= src/
OBJ_DIR		= obj/
# CC			= gcc -fsanitize=address
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f
AR			= ar rcs
LFT			= -lft -L.

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
SRC_FILES	=	main operations operations_bis operations_bis_2 small_sort big_sort utils utils2 lists_utils

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###mak

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@$(CC) $(OBJ) $(LFT) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)" 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)" 
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@$(RM) -rf ./libft.a
			@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

go:
			leaks --atExit -- ./push_swap "1 4 2 3 5 6 7 8 9"

val:
			valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --verbose ./push_swap 1 4 2 3 5 6 7 8 9

.PHONY:		all clean fclean re norm
