# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 17:19:15 by orhernan          #+#    #+#              #
#    Updated: 2025/11/28 13:32:58 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

# Directories
SRC_DIR		:= src
INC_DIR		:= inc
OBJ_DIR		:= obj
TEST_DIR	:= .test
LIBFT_DIR	:= libft

# Files
NAME		:= libftprintf.a
LIBFT		:= $(LIBFT_DIR)/libft.a

# Tools & Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MD -I $(INC_DIR) -I $(LIBFT_DIR)
RM			:= rm -f
AR			:= ar rcs
PRINTF		:= printf

# Source and object files
SRC		= $(addprefix $(SRC_DIR)/,	\
		ft_printf.c	ft_parse_specifier.c	ft_print_char.c	\
		ft_print_hex.c	ft_print_str.c		ft_print_ptr.c	\
		ft_print_int.c	ft_print_uint.c		ft_putnbr_base_fd.c)
OBJ 		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP		= $(OBJ:.o=.d)

# Build Rules
$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) all -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(PRINTF) "Creating $(NAME) ...\n"
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

# Targets
all: $(NAME)

clean:
	@$(PRINTF) "Cleaning up object files in ft_printf...\n\n"
	$(MAKE) clean -C $(LIBFT_DIR) || true
	$(RM) -r $(OBJ_DIR)
	@$(PRINTF) "Removed object files\n"

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR) || true
	$(RM) $(NAME)
	@$(PRINTF) "Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re test
