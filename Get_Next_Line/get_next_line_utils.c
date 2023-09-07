/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/07 16:17:26 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	if (s == NULL)
		return (0);
	i = 0;
	str = (unsigned char *)s;
	while (str[i] != (char) c)
	{
		if (str[i] == '\0')
			return (0);
		else
			i++;
	}
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (gnl_free(&s1));
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	free(s1);
	return (str);
}

unsigned char	*str_gen(unsigned int start, size_t fin)
{
	unsigned char	*str;

	if ((int)fin - (int)start > 0)
		str = (unsigned char *)malloc(fin - start + 1);
	else
		str = (unsigned char *)malloc(1);
	if (!str)
		return (0);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned char	*str;
	size_t			fin;

	i = 0 - 1;
	if (start > ft_strlen((char *)s))
	{
		str = (unsigned char *)malloc(1);
		if (!str)
			return (0);
		return ((char *)str);
	}
	if (start + len < ft_strlen((char *)s))
		fin = start + len;
	else
		fin = ft_strlen((char *)s);
	str = str_gen(start, fin);
	if (str == 0)
		return (0);
	if (start >= ft_strlen((char *)s))
		return ((char *)str);
	while (++i < fin - start)
		str[i] = s[i + start];
	str[i] = '\0';
	return ((char *)str);
}
