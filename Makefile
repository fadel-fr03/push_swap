# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 17:15:04 by fal-frou          #+#    #+#              #
#    Updated: 2025/05/15 15:08:34 by fal-frou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		Directories		#
SRCDIR	=	src
INCDIR	=	inc
B_SRCDIR	=	bonus_src
B_INCDIR = bonus_inc

#		Includes		#
INCLUDES	= -I ${INCDIR} -I ${B_INCDIR}

#		Source Files		#
SRCS	= src/check_validity.c src/free_functions.c src/ft_split.c \
		  src/ft_substr.c src/initialize_stack.c src/move.c \
		  src/prepare_a_to_b.c src/prepare_b_to_a.c src/push_operation.c \
		  src/push_swap.c src/reverse_rotate_operation.c src/rotate_operation.c \
		  src/sort_three.c src/sort_utils.c src/stack_utils.c \
		  src/swap_operation.c src/turk_sort.c
B_SRCS	= bonus_src/checker_utils.c bonus_src/checker.c bonus_src/get_next_line_utils.c \
		  bonus_src/get_next_line.c

#		Object Files		#
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

#		Variables		#
NAME	= push_swap
CHECKER_NAME	= checker
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

#		Default Target		#
all: $(NAME)

#		Linking the push_swap Executable		#
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) ${INCLUDES} $(OBJS) -o $(NAME)

#		Linking the checker Executable		#
${CHECKER_NAME}:	${B_OBJS} ${OBJS:$(SRCDIR)/push_swap.o=}
	$(CC) $(CFLAGS) ${INCLUDES} ${B_OBJS} ${OBJS:$(SRCDIR)/push_swap.o=} -o ${CHECKER_NAME}

#		Bonus Rule#
bonus:	${NAME} ${CHECKER_NAME}

#		Compilation Rules		#
%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $@

#		Cleaning Object Files		#
clean:
	$(RM) $(OBJS) ${B_OBJS}

#		Cleaning Object Files and Executable		#
fclean: clean
	$(RM) $(NAME) ${CHECKER_NAME}

#		Rebuild Everything		#
re: fclean all

.PHONY: all clean fclean re bonus
