# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esellier <esellier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:01:31 by ineimatu          #+#    #+#              #
#    Updated: 2025/03/04 12:31:35 by esellier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
MLX = mlx_linux/
GNL = gnl/
LIBFT = libft/
MLX_A = $(addprefix $(MLX), libmlx.a)
GNL_A = $(addprefix $(GNL), libgnl.a)
LIBFT_A = $(addprefix $(LIBFT), libft.a)

SRC = main.c \
	  parsing/parsing.c \
	  parsing/parsing_colors.c \
	  parsing/parsing_textures.c \
	  parsing/parsing_map.c \
	  utils.c \
	  mini_map.c \
	  events.c \
	  ray_cast.c \
	  ray_cast_calcul.c \
	  ray_cast_utils.c \
	  textures.c \
	  texture_utils.c \
	  door.c \
	  sprite.c \
	  initialize.c

SRC_BONUS =

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc

INCLUDES = -I includes -I $(LIBFT) -I $(GNL)

CCFLAGS = -Wall -Wextra -Werror $(INCLUDES) -fsanitize=address -fsanitize=leak

all:
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(GNL)
	@$(MAKE) -C $(MLX)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o:		%.c Makefile includes/cub3D.h includes/struct.h $(LIBFT_A) $(GNL_A) $(MLX_A)
			$(CC) $(CCFLAGS) -Imlx_linux -O3 -c $< -o $(<:.c=.o)

bonus: .bonus
	
.bonus : $(NAME) $(OBJ_BONUS)
	touch .bonus
	ar rcs $(NAME) $(OBJ_BONUS)
	
clean:
			rm -f $(OBJ) $(OBJ_BONUS)
			$(MAKE) clean -s -C $(GNL)
			$(MAKE) clean -s -C $(LIBFT)

fclean:		clean
			$(MAKE) clean -s -C $(MLX)
			$(MAKE) fclean -s -C $(GNL)
			$(MAKE) fclean -s -C $(LIBFT)
			rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus

# all : $(NAME)

# %.o : %.c Makefile libft.h
# 	$(CC) $(FLAGS) -o $@ -c $<

# $(NAME) : $(OBJ)
# 	ar rcs $(NAME) $(OBJ)

# bonus: .bonus

# .bonus : $(NAME) $(OBJ_B)
# 	touch .bonus
# 	ar rcs $(NAME) $(OBJ_B)

# clean :
# 	rm -f *.o .bonus

# fclean : clean
# 	rm -f $(NAME)
