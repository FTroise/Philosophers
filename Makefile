# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftroise <ftroise@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 16:17:57 by ftroise           #+#    #+#              #
#    Updated: 2024/02/25 16:17:57 by ftroise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Define color codes for a bit of creativity
RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
CYAN = \033[36m
YELLOW = \033[33m
RED = \033[31m

# Project name


NAME = philo

# Source files
FILES = init.c \
        routine.c \
        main.c \
        utils.c

# Object files
OBJS = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# Rule to compile C source files to object files
.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiled:$(RESET) $<"

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(CYAN)Project Built!$(RESET)"

# Default target
all: $(NAME)

# Rule to clean object files
clean:
	@$(RM) $(OBJS)
	@echo "$(BOLD)$(YELLOW)Cleaned up object files.$(RESET)"

# Rule to clean everything (object files and the executable)
fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD)$(YELLOW)Removed executable.$(RESET)"

# Rule to recompile everything
re: fclean all

# Don't treat these targets as files
.PHONY: all clean fclean re
