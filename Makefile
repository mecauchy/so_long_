# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:00:29 by mcauchy-          #+#    #+#              #
#    Updated: 2025/02/07 10:41:35 by mcauchy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 SRC_FILES		=	$(wildcard srcs/*.c)
 
 LIBFT			=	libft/libft.a
 
 MLX			=	minilibx-linux/libmlx_Linux.a 
 
 INCLUDES		=	-I . \
 					-I /libft \
					-I minilibx-linux/mlx \
			
OBJ_FILES		=	$(SRC_FILES:.c=.o)

CC				=	gcc -g3

CFLAGS0			=	-Wall -Wextra -Werror

NAME			=	so_long

all				:	$(NAME)

$(NAME)			:	$(OBJ_FILES) $(LIBFT) $(MLX)
					$(CC) $(OBJ_FILES) $(LIBFT) $(MLX) -lXext -lX11 -lm -lz $(CFLAGS) -no-pie -o $(NAME)
			
%.o				:	%.c 
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	
$(LIBFT)		:
					$(MAKE) -C libft/

clean			:
					rm -rf $(OBJ_FILES)
					cd srcs/; rm -rf *.o
					$(MAKE) fclean -C libft/
		
fclean			:	clean
					rm -rf $(NAME)
		
re				:	fclean all

.PHONY			:	all clean fclean re