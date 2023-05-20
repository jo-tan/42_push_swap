# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 14:50:21 by jo-tan            #+#    #+#              #
#    Updated: 2023/03/28 15:26:18 by jo-tan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

NAME		= push_swap.a
EXEC		= push_swap

CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RN) $(NAME)
			$(CC) $(CFLAGS) $(SRCS) -L. $(NAME) -o push_swap

all:		$(NAME)
			
clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) $(EXEC)

re:		fclean all

.PHONY:		all clean fclean re
