# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:00:29 by mcauchy-          #+#    #+#              #
#    Updated: 2025/02/05 15:37:59 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c move.c parsing.c utils.c

HEADER	=	so_long.h 

CC		=	cc 

CFLAGS	=	-Wextra -Wall -Werror -g3 

LDFLAGS	=	-Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_DIR	=	./minilibx_linux --no-print-directory 

OBJS	=	$(SRCS.c=.o)

PRINTF_OBJS	=	$(PRINTF_OBJS.c=.o)

$(LIBFT):
			@$(MAKE) -C $(LIBFT_DIR) 

$(NAME)	:	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME) 

all		:	$(NAME)
		
%.o		:	%.c
			$(HEADER) @$(CC) $(CFLAGS) -Iincludes -Imlx -c $< -o $@ 

clean	:
			@rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ) @$(MAKE) clean -C $(LIBFT_DIR) 

fclean	:	clean
			@rm -f $(NAME) @$(MAKE) fclean -C $(LIBFT_DIR) 

re		:	fclean all 

.PHONY	:	all clean fclean re