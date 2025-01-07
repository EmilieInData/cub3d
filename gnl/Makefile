# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 14:39:37 by ineimatu          #+#    #+#              #
#    Updated: 2024/06/07 11:19:27 by ineimatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

HEADER = get_next_line.h

SRC = get_next_line.c \
	  get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
