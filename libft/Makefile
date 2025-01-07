# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ineimatu <ineimatu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:42:44 by ineimatu          #+#    #+#              #
#    Updated: 2024/06/07 11:19:18 by ineimatu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strlcat.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_calloc.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_itoa.c \
	   ft_split.c \
	   ft_strcpy.c \

OBJ = $(SRCS:.c=.o)

HEADER = libft.h

CC = cc

CCFLAGS = -Wall -Wextra -Werror

all : $(NAME) 

%.o: %.c $(HEADER) Makefile
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME) : $(OBJ) 
	ar rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re 
