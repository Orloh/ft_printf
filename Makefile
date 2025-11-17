# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:19:15 by orhernan          #+#    #+#              #
#    Updated: 2025/11/13 23:37:42 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj
BIN_DIR		= bin
TEST_DIR	= test
LIBFT_DIR	= libft

# Files
BIN		= libftprintf.a
NAME		= $(BIN_DIR)/$(BIN)
LIBFT		= $(LIBFT_DIR)/libft.a

# Tools & Flags
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -MD -I$(INC_DIR) -I$(LIBFT_DIR)
RM		= rm -f
AR		= ar rcs
PRINTF		= printf

# Source and object files
SRC		= $(SRC_DIR)/ft_printf.c
OBJ 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP		= $(OBJ:.o=.d)

# Build Rules
$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ) | $(BIN_DIR)
	$(PRINTF) "Creating $(BIN) ...\n"
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

# Targets
all: $(NAME)

clean: | $(LIBFT_DIR)
	@$(PRINTF) "Cleaning up object files in ft_printf...\n\n"
	$(MAKE) clean -C $(LIBFT_DIR) || true
	$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "Removed object files\n"

fclean: clean
	$(RM) -r $(BIN_DIR)
	@$(PRINTF) "Removed $(NAME)\n"

re: fclean all

test: all
	$(MAKE) all -C $(TEST_DIR)

.PHONY: all clean fclean re test
