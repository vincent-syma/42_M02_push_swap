NAME = push_swap
CHECKER_NAME = checker

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar rcs

INC_DIR = include
SRC_DIR = src
OBJ_DIR = temp
VPATH = $(SRC_DIR)

LIB_DIR = 42_library
LIB_INC_DIR = $(LIB_DIR)/include

INCLUDES = -I$(INC_DIR) -I$(LIB_INC_DIR)

SRC = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/push_swap_input.c \
		$(SRC_DIR)/push_swap_errors.c \
		$(SRC_DIR)/push_swap_nodes_1.c \
		$(SRC_DIR)/push_swap_nodes_2.c \
		$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/push_swap_rotate_reverse.c \
		$(SRC_DIR)/push_swap_rotate_index_top.c \
		$(SRC_DIR)/push_swap_sort.c \
		$(SRC_DIR)/push_swap_chunk_sort.c \
		$(SRC_DIR)/push_swap_min_max_index.c \
		$(SRC_DIR)/push_swap_index_cost.c

CHECKER_SRC = \
			$(SRC_DIR)/checker.c \
			$(SRC_DIR)/push_swap_input.c \
			$(SRC_DIR)/push_swap_errors.c \
			$(SRC_DIR)/push_swap_nodes_1.c \
			$(SRC_DIR)/push_swap_nodes_2.c \
			$(SRC_DIR)/push_swap_checker.c \
			$(SRC_DIR)/push_swap_rotate_reverse_checker.c

# --- colours ---
RESET := \033[0m
BOLD  := \033[1m
RED   := \033[31m
GRN   := \033[32m
YEL   := \033[33m
BLU   := \033[34m

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ) $(LIB_DIR)/libft.a
		@$(MAKE) -C $(LIB_DIR)
		@printf "Compiling the $(BOLD)'push_swap'$(RESET) program"
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB_DIR)/libft.a -o $(NAME) && \
		printf "%-10s[$(GRN)OK$(RESET)]\n" || \
		(printf "[$(RED)FAIL$(RESET)]\n"; exit 1)
		@printf "$(YEL)Run the program as follows:\n"
		@printf '$(RESET)ARG=\"4 67 3 87 23\"; ./push_swap $$ARG\n'
		@printf "$(YEL)(the args are up to you)\n$(RESET)"

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

all: $(NAME)

checker: $(CHECKER_OBJ) $(LIB_DIR)/libft.a
		@$(MAKE) -C $(LIB_DIR)
		@printf "Compiling the $(BOLD)'checker'$(RESET) program"
		@$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_OBJ) $(LIB_DIR)/libft.a -o $(CHECKER_NAME) && \
		printf "%-10s[$(GRN)OK$(RESET)]\n" || \
		(printf "[$(RED)FAIL$(RESET)]\n"; exit 1)
		@printf "$(YEL)Run the program as follows:\n"
		@printf '$(RESET)ARG=\"4 67 3 87 23\"; ./push_swap $$ARG | ./checker $$ARG \n'
		@printf "$(YEL)(the args are up to you)\n$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@printf "CC %-35s" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && \
		printf "[$(GRN)OK$(RESET)]\n" || \
		(printf "[$(RED)FAIL$(RESET)]\n"; exit 1)

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLU)Push_swap (and checker) objects have been deleted.$(RESET)\n"

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(CHECKER_NAME)
	@printf "$(BLU)Push_swap (and checker) has been deleted.$(RESET)\n"

clean_lib:
	@$(MAKE) clean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re checker clean_lib
