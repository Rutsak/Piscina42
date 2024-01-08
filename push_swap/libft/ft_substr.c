/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:02:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/16 14:35:20 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
/*
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char				*str;
	size_t				i;

	str = (char *)s;
	i = 0;
	if (n == 0)
		i = 0;
	else
	{
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*mem;
	size_t		i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, (count * size));
	return (mem);
}
*/

static unsigned char	*str_gen(unsigned int start, size_t fin)
{
	unsigned char	*str;

	if ((int)fin - (int)start > 0)
		str = (unsigned char *)ft_calloc(1, fin - start + 1);
	else
		str = (unsigned char *)ft_calloc(1, 1);
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
		str = (unsigned char *)ft_calloc(1, 1);
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
/*
	scopy = (char *)s;
	i = 0;
	s_size = ft_strlen((char *)scopy);
	if (start > s_size)
	{
		str = (unsigned char *)ft_calloc(1, 1);
		return ((char *)str);
	}
	if (start + len < s_size)
		fin = start + len;
	else
		fin = s_size;
	if ((int)fin - (int)start > 0)
		str = (unsigned char *)ft_calloc(1, fin - start + 1);
	else
		str = (unsigned char *)ft_calloc(1, 1);
	if (!str)
		return (0);
	if (start >= s_size)
		return ((char *)str);
	while (i < fin - start)
	{
		str[i] = scopy[i + start];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}

int	main(void)
{
	char			*a;
	char			s[30]= "Hola";
	unsigned int	start;
	size_t			len;

	start = 4294967295;
	len = 0;
	a = ft_substr(s, start, len);
	printf("%s", a);
}
*/