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

# Directory & File structure
SRC_DIR		= src
INC_DIR		= inc
OBJ_DIR		= obj
BIN_DIR		= bin
TEST_DIR	= test
BIN		= libftprintf.a
NAME		= $(BIN_DIR)/$(BIN)
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/bin/libft.a
# LIBFT_SRC	= $(shell [ -d libft ] && libft/src/*.c)

# Tools & Flags
CC		= cc -MD
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
RM		= rm -f
AR		= ar rcs
PRINTF		= printf

# Source and object files
SRC		= ft_printf.c
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build Rules
$(BIN_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): | $(LIBFT_DIR) $(BIN_DIR)
	@make all -C $(LIBFT_DIR)
	@$(AR) $(NAME) $(LIBFT)

$(NAME): $(LIBFT) $(OBJ) | $(BIN_DIR)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

# Cleaning rules

clean: | $(LIBFT_DIR)
	@$(PRINTF) "Cleaning up object files in ft_printf...\n\n"
	@make clean -C $(LIBFT_DIR) || true
	@$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "Removed object files"

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "Removed $(NAME)\n"
	@$(RM) $(LIBFT)
	@$(PRINTF) "Removed $(LIBFT)\n"

re: fclean
	@make all

test:
	@make -C $(TEST)

-include $(OBJ_DIR)/*.d

.PHONY all clean fclean re
