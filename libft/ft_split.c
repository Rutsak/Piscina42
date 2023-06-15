/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:46:48 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/15 17:55:06 by doller-m         ###   ########.fr       */
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
	if (*front == '\0')
		return (0);
	while (*front == c)
	{
		front++;
		l++;
	}
	if (*front == 0)
		return (-1);
	rear = front;
	while (*rear != '\0')
	{
		if (*rear == c)
			return (l);
		rear++;
		l++;
	}
	return (l);
}

void	freewilly(char **index, int i)
{
	while (i > 0)
	{
		free (index[i - 1]);
		i--;
	}
	free (index);
}

int	split_write(char *front, int words, char c, char **index)
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
		index[i] = ft_calloc((sizeof (char)), rear - front + 1);
		if (!index[i])
		{
			freewilly(index, i);
			return (0);
		}
		ft_strlcpy(index[i], front, rear - front +1);
		if (ft_strchr(rear, c) == rear + 1)
			rear++;
		front = rear + 1;
		i++;
	}
	index[i] = NULL;
	return (1);
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
	while (word_lcounter(&front[len], c) > 0 && front[len] != '\0')
	{
		len = len + word_lcounter(&front[len], c);
		words++;
	}
	index = malloc((sizeof (char *)) * (words + 1));
	if (!index)
		return (0);
	front = (char *)s;
	if (split_write(front, words, c, index) == 0)
		return (0);
	return (index);
}
/* 
int	main(void)
{
	char		**index;
	char		c = '\0';
	char s[100] = "nonempty";

	index = ft_split(s, c);
	printf("%s\n", index[0]);
	//printf("%s", index[1]);
	return (0);
}
 */