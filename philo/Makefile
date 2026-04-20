# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 05:09:46 by vbleskin          #+#    #+#              #
#    Updated: 2026/04/20 22:45:00 by vlad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

# ------------------------------------------------------------------------------
# DEFINITIONS
# ------------------------------------------------------------------------------

CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I includes -g3 -pthread
RM				= rm -rf

# ------------------------------------------------------------------------------
# DIRECTORIES
# ------------------------------------------------------------------------------

SRC_DIR			=	src/
OBJ_DIR			=	obj/

# ------------------------------------------------------------------------------
# FILES
# ------------------------------------------------------------------------------

SRC_FILES		=	main.c \
					init.c \
					philo_process.c \
					spectator_process.c \
					utils/checker.c \
					utils/ft_atoi.c \
					utils/io.c \
					utils/time.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# ------------------------------------------------------------------------------
# RULES
# ------------------------------------------------------------------------------

all :			$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $<"

$(NAME) :		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(NAME) compiled successfully"

clean :
				@$(RM) $(OBJ_DIR)
				@echo "Objects cleaned successfully"

fclean :		clean
				@$(RM) $(NAME)
				@echo "Executable cleaned successfully"

re :			fclean all

.PHONY:			all clean fclean re