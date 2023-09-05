/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:45:31 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/04 15:10:44 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
char			*gnl_strjoin(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*analisis(char **str_work);
char			*get_next_line(int fd);
unsigned char	*str_gen(unsigned int start, size_t fin);
char			*gnl_free(char **str);

#endif
