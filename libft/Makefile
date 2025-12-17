# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 12:45:24 by orhernan          #+#    #+#              #
#    Updated: 2025/10/22 00:18:50 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Debug flags (debug symbols, no optimizatinos)
DEBUG_FLAGS = -Wall -Werror -Wextra -g -O0

# Archiver
AR = ar

# Archiver flags
ARFLAGS = rcs

# Include directory
ROOT = .

# Preprocessor flags
CPPFLAGS = -I$(ROOT)

# Detect operating system to select file deleting program
ifeq ($(OS),Windows_NT)
    # Windows: Use del /Q
    RM = del /Q
    EXTENSION = exe
else
    # Linux/Unix: Use rm -f
    RM = rm -f
    EXTENSION = out
endif

# Source files
SRCS =		ft_atoi.c	ft_bzero.c	ft_calloc.c	ft_isalnum.c	\
		ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	\
		ft_itoa.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	\
		ft_memmove.c	ft_memset.c	ft_putchar_fd.c	ft_putendl_fd.c	\
		ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c	ft_strchr.c	\
		ft_strdup.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c	\
		ft_strlcpy.c	ft_strlen.c	ft_strmapi.c	ft_strncmp.c	\
		ft_strnstr.c	ft_strrchr.c	ft_substr.c	ft_strtrim.c	\
		ft_tolower.c	ft_toupper.c

# Bonus Source files
BONUS_SRCS =	ft_lstnew_bonus.c	ft_lstadd_front_bonus.c	ft_lstadd_back_bonus.c	\
		ft_lstsize_bonus.c	ft_lstlast_bonus.c	ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c	ft_lstiter_bonus.c	ft_lstmap_bonus.c	

# Main.out
MAIN = main.out

# Name of static libraries
NAME = libft.a
DEBUG_NAME = libft_debug.a

# Header files
HEADERS = libft.h

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEBUG_OBJS = $(SRCS:.c=_debug.o)
DEBUG_BONUS_OBJS = $(BONUS_SRCS:.c=_debug.o)
ALL_OBJS = $(OBJS) $(BONUS_OBJS) $(DEBUG_OBJS) $(DEBUG_BONUS_OBJS)

# Compilation rule for objects
%.o: %.c $(HEADERS) 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilation rule for debug objects
%_debug.o: %.c $(HEADERS)
	$(CC) $(DEBUG_FLAGS) $(CPPFLAGS) -c $< -o $@

# Release library
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Debug library
$(DEBUG_NAME): $(DEBUG_OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Default target
all: $(NAME)

# Debug target
debug: $(DEBUG_NAME)

# Add bonus to realese library
bonus: $(OBJS) $(BONUS_OBJS)
	@echo "Updating $(NAME) with bonus functions..."
	$(AR) r $(NAME) $(BONUS_OBJS)

# Add debug bonus to debug library
bonus_debug: debug $(DEBUG_BONUS_OBJS)
	@echo "Updating $(DEBUG_NAME) with bonus functions..."
	$(AR) r $(DEBUG_NAME) $(DEBUG_BONUS_OBJS)

# Clean up generated object files 
clean: 
	$(RM) $(ALL_OBJS)

# Clean everyting
fclean: clean
	$(RM) $(NAME) $(DEBUG_NAME) $(MAIN)

# Rebuild project
re: fclean all

# Rebuild debug
redebug: fclean debug

# Link a test program to the debug library
test_debug: bonus_debug
	$(CC) main.c -o main.$(EXTENSION) $(DEBUG_FLAGS) $(CPPFLAGS) -L$(ROOT) -lft_debug

# Phony targets
.PHONY: all debug bonus bonus_debug clean fclean re test_debug
