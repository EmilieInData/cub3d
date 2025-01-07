/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:07:49 by ineimatu          #+#    #+#             */
/*   Updated: 2024/06/18 16:07:44 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
size_t	ft_strln(const char *c);
int		ft_strcr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_empty_file(char *buff);
char	*ft_free(char *buffer, char *buf);
#endif
