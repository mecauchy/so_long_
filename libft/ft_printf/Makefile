# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 13:29:09 by mcauchy-          #+#    #+#              #
#    Updated: 2024/11/16 14:20:12 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_printf.c putnbrs.c search_other.c search.c srcs.c main.c
			
OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

DEBUG	=	-g3

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc $@ $^

main	:	all
			$(CC) main.c libftprintf.a -o main

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $^

clean	:	
			/bin/rm -rf $(OBJS) main.o

fclean	:	clean
			/bin/rm -rf $(NAME) main

re		:	fclean all