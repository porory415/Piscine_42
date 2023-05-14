# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 20:20:55 by gaeokim           #+#    #+#              #
#    Updated: 2022/06/07 19:06:23 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_make_map.c ft_find_bsq.c ft_util.c ft_split.c
OBJS	= $(addprefix ./srcs/, $(SRCS:.c=.o))
INC	= includes
NAME	= bsq
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $@ $^
	$(CC) $(CFLAGS) $@ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re