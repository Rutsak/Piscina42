/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:48 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/12 10:44:39 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
/* 
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

void	escriu(char *dst, const char *src, size_t dstsize, size_t len)
{
	size_t	l;

	l = 0;
	if (dstsize > len)
	{
		while (src[l])
		{
			dst[l] = src[l];
			l++;
		}
	}
	else
	{
		while (l != dstsize - 1)
		{
			dst[l] = src[l];
			l++;
		}
	}
	dst[l] = '\0';
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*src1;
	size_t	len;

	src1 = (char *)src;
	len = ft_strlen(src1);
	if (dstsize != 0)
	{
		escriu(dst, src, dstsize, len);
	}
	return (len);
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

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != c)
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
 */
int	word_lcounter(char *front, char c)
{
	int		l;
	char	*rear;

	l = 0;
	while (*front == c)
	{
		front++;
		l++;
	}
	if (*front == 0)
	{
		return (-1);
	}
	rear = front;
	while (*rear != '\0')
	{
		if (*rear == c)
		{
			return (l);
		}
		rear++;
		l++;
	}
	return (l);
}


void	freewilly(char **index, int i)
{
	i++;
	while (i > 0)
	{
		free (index[i - 1]);
		i--;
	}
	free (index);
}

void	split_write(char *front, int words, char c, char **index)
{
	int		i;
	char	*rear;

	i = 0;
	while (i < words)
	{
		while (*front == c)
			front++;
		rear = ft_strchr(front, c);
		if (rear == NULL)
			rear = ft_strchr(front, '\0');
		index[i] = ft_calloc((sizeof (char)), rear - front + 2);
		if (!index[i])
			freewilly(index, i);
		ft_strlcpy(index[i], front, rear - front +1);
		if (ft_strchr(rear, c) == rear + 1)
			rear++;
		front = rear + 1;
		i++;
	}
	index[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char		**index;
	char		*front;
	int			words;
	int			len;

	words = 0;
	len = 0;
	front = (char *)s;
	if (c == '\0')
	{
		index = ft_calloc((sizeof (char *)), 2);
		while (s[len] != '\0')
		{
			index[0][len] = s[len];
			len++;
		}
		return (index);
	}
	while (word_lcounter(&front[len], c) > 0)
	{
		len = len + word_lcounter(&front[len], c);
		words++;
	}
	if (words == 0)
		return (ft_calloc((sizeof (char *)), 1));
	index = malloc((sizeof (char *)) * (words + 1));
	if (!index)
		return (0);
	front = (char *)s;
	split_write(front, words, c, index);
	return (index);
}
/* 
int	main(void)
{
	char	c = '-';
	char	s[84] = "--1-2--3---4----5-----42";

	ft_split(s, c);
	return (0);
}
 */