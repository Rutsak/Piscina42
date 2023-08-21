/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutsak <rutsak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/08/21 09:21:52 by rutsak           ###   ########.fr       */
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

static void	s1_result(char const *s1, char *resul)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		resul[i] = s1[i];
		i++;
	}
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*resul;
	int		i;
	int		ls1;
	int		ls2;

	if (!s1)
		ls1 = 0;
	else
		ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	resul = malloc(ls1 + ls2 + 1);
	if (!resul)
		return (NULL);
	if (s1)
		s1_result(s1, resul);
	i = 0;
	while (i < (int)ft_strlen((char *)s2))
	{
		resul[ls1 + i] = s2[i];
		i++;
	}
	resul[ls1 + i] = '\0';
	free (s1);
	return (resul);
}
