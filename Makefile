# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esellier <esellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:01:31 by ineimatu          #+#    #+#              #
#    Updated: 2025/01/13 17:50:27 by esellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX = mlx_linux/
PRINTF = ft_printf/
GNL = gnl/
LIBFT = libft/
MLX_A = $(addprefix $(MLX), libmlx.a)
PRINTF_A = $(addprefix $(PRINTF), libft_printf.a)
GNL_A = $(addprefix $(GNL), libgnl.a)
LIBFT_A = $(addprefix $(LIBFT), libft.a)

SRC = main.c \
	  parsing.c \
	  map_parsing.c \
	  utils.c

OBJ = $(SRC:.c=.o)

CC = cc

INCLUDES = -I includes -I $(LIBFT)libft.h -I $(PRINTF)ft_printf.h -I $(GNL)get_next_line.h

CCFLAGS = -Wextra -Werror -Wall $(INCLUDES)

all:
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(PRINTF)
	@$(MAKE) -C $(GNL)
	@$(MAKE) -C $(MLX)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(PRINTF) -lft_printf -L$(GNL) -lgnl -L$(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:		%.c Makefile includes/so_long.h includes/so_l_utils.h $(LIBFT_A) $(PRINTF_A) $(GNL_A) $(MLX_A)
			$(CC) $(CCFLAGS) -Imlx_linux -O3 -c $< -o $(<:.c=.o)
clean:
			rm -f $(OBJ)
			$(MAKE) clean -s -C $(PRINTF)
			$(MAKE) clean -s -C $(GNL)
			$(MAKE) clean -s -C $(LIBFT)

fclean:		clean
			$(MAKE) clean -s -C $(MLX)
			$(MAKE) fclean -s -C $(GNL)
			$(MAKE) fclean -s -C $(PRINTF)
			$(MAKE) fclean -s -C $(LIBFT)
			rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

