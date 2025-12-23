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

# Name of static libraries
NAME = libft.a

# Header files
HEADERS = libft.h

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
ALL_OBJS = $(OBJS) $(BONUS_OBJS)

# Compilation rule for objects
%.o: %.c $(HEADERS) 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Release library
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Default target
all: $(NAME)

# Add bonus to realese library
bonus: $(OBJS) $(BONUS_OBJS)
	@printf "Updating $(NAME) with bonus functions...\n"
	$(AR) r $(NAME) $(BONUS_OBJS)

# Clean up generated object files 
clean: 
	$(RM) $(ALL_OBJS)

# Clean everyting
fclean: clean
	$(RM) $(NAME)

# Rebuild project
re: fclean all

# Phony targets
.PHONY: all debug bonus bonus_debug clean fclean re test_debug
