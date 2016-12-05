# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:34:56 by mhurd             #+#    #+#              #
#    Updated: 2016/12/04 16:44:06 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

SRC1	=	push_swap.c \
			push.c \
			rotate.c \
			rrotate.c \
			swap.c \
			helper.c \
			check_list.c \
			simple_sort.c \
			sort_tools.c \
			slow_sort.c

SRC2	=	checker.c \
			push.c \
			rotate.c \
			rrotate.c \
			swap.c \
			check_list.c \
			helper.c

OBJ1		= $(addprefix $(OBJDIR),$(SRC1:.c=.o))
OBJ2		= $(addprefix $(OBJDIR),$(SRC2:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME1) $(NAME2)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $(NAME2) $(OBJ2) $(LIBLINK)

$(NAME1): $(OBJ1)
	$(CC) $(LDFLAGS) -o $(NAME1) $(OBJ1) $(LIBLINK)


clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C ./libft fclean

re: fclean all
