# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 14:58:56 by ineimatu          #+#    #+#              #
#    Updated: 2024/06/07 11:19:39 by ineimatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

HEADER = ft_printf.h

SRCS = ft_putchar.c \
	   ft_printf.c \
	   ft_putstr.c \
	   ft_putnbr.c \
	   ft_hexad.c \

OBJS= $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
