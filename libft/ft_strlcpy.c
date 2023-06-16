/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:56 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/16 14:35:37 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/*size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while(src[i] != '\0')
	{
		printf("FT src[i]: %c\n", src[i]);
		i++;

	}
	return (i);
}*/

static void	escriu(char *dst, const char *src, size_t dstsize, size_t len)
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

/*#include <stdio.h>
#include <string.h>
int main(void)
{
//	char    dest[10];
	const char  src[] = "Hola\0";
//	char    dest2[10];
	const char  src2[] = "Hola\0";
	size_t  n = 2;
	printf("recplica: %zu\n", ft_strlcpy((char *)src + 1, src, n));
	printf("recplica: %s\n", src + 1);
	printf("original: %zu\n", strlcpy((char *)src + 1, src2, n));
	printf("original: %s\n", src + 1);
}*/
