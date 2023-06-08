/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:48 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/08 12:14:33 by doller-m         ###   ########.fr       */
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
int	word_counter(char *front, char *rear, char c)
{
	int words;

	words = 0;
	while (*front == c)
		front++;
	if (*front == 0)
	{
		return (-1);
	}
	rear = front + 1;
	while (*rear != '\0')
	{
		if (*rear == c && (*(rear + 1) != c))
		{
			front = rear + 1;
			words++;
		}
		rear++;
	}
	return (words);
}


void freewilly(char **index, int i)
{
	i++;
	while (i > 0)
	{
		free (index[i - 1]);
		i--;
	}
	free (index);
}

char	**ft_split(char const *s, char c)
{
	char		**index;
	char		*front;
	char		*rear;
	int			words;
	int			i;

	words = 0;
	front = (char *)s;
	rear = front;
	words = word_counter(front, rear, c);
	if (words == -1)
		return (ft_calloc((sizeof (char *)), 1));
	index = ft_calloc((sizeof (char *)), words + 1);
	if (!index)
		return (0);
	front = (char *)s;
	i = 0;
	while (i <= words)
	{
		while (*front == c)
			front++;
		rear = ft_strchr(front, c);
		if (rear == 0)
			rear = ft_strchr(front, '\0');
		else if (rear[0] == rear[1])
			while (rear[0] == rear[1])
				rear++;
		index[i] = ft_calloc((sizeof (char)), rear - front + 2);
		if (!index[i])
			freewilly(index, i);
		ft_strlcpy(index[i], front, rear - front +1);
		if (ft_strchr(rear, c) == rear + 1)
			rear++;
		front = rear + 1;
		i ++;
	}
//	index[++i] = ft_calloc((sizeof (char)), 1);
//	if (!index[i])
//		freewilly(index, i);
	return (index);
}
/* 
int	main(void)
{
	char	c = ' ';
	char	s[84] = "  lorem  ipsum dolor sit amet, consectetur adipiscing elit.  risus. Suspendisse     ";

	ft_split(s, c);
	return (0);
}
 */