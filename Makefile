# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 05:09:46 by vbleskin          #+#    #+#              #
#    Updated: 2026/04/17 18:03:16 by vlad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# EXE
# ------------------------------------------------------------------------------

NAME			=	philo
NAME_BONUS		=	philo_bonus

# ------------------------------------------------------------------------------
# DEFINITIONS
# ------------------------------------------------------------------------------

CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I includes -g3 -pthread
MAKEFLAGS 		+=	--no-print-directory
RM				= rm -rf

# ------------------------------------------------------------------------------
# DIRECTORIES
# ------------------------------------------------------------------------------

SRC_DIR			=	src/
OBJ_DIR			=	obj/
OBJ_DIR_BONUS	=	obj_bonus/

# ------------------------------------------------------------------------------
# FILES
# ------------------------------------------------------------------------------

SRC_COMMON		=	utils/ft_atoi.c \
					utils/io.c \
					utils/time.c

SRC_MANDATORY	=	mandatory/main.c \
					mandatory/init.c \
					mandatory/checker.c \
					mandatory/philo_process.c \
					mandatory/spectator_process.c

SRC_BONUS		=	bonus/main.c

SRCS_MANDATORY	=	$(addprefix $(SRC_DIR), $(SRC_COMMON) $(SRC_MANDATORY))
SRCS_BONUS		=	$(addprefix $(SRC_DIR), $(SRC_COMMON) $(SRC_BONUS))

OBJS_MANDATORY	=	$(addprefix $(OBJ_DIR), $(SRC_COMMON:.c=.o) $(SRC_MANDATORY:.c=.o))
OBJS_BONUS		=	$(addprefix $(OBJ_DIR_BONUS), $(SRC_COMMON:.c=.o) $(SRC_BONUS:.c=.o))

# ------------------------------------------------------------------------------
# RULES
# ------------------------------------------------------------------------------

all :			$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $<"

$(NAME) :		$(OBJS_MANDATORY)
				@$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME)
				@echo "$(NAME) compiled successfuly"

bonus :			$(NAME_BONUS)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $< (bonus)"

$(NAME_BONUS) :	$(OBJS_BONUS)
				@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
				@echo "$(NAME_BONUS) compiled successfuly"

clean :
				@$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
				@echo "$(NAME) cleaned successfuly"

fclean :		clean
				@$(RM) $(NAME) $(NAME_BONUS)

re :			fclean all

.PHONY:			all clean fclean re