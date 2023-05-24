/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:56 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/24 17:23:11 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include "libft.h"
#include "ft_strlen.c"
#include <stdio.h>
#include <string.h>


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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	char 	*src1 = (char *)src;
	size_t	len;

	len =ft_strlen(src1);
	l = 0;
	if (dstsize != 0)
	{
		if(dstsize > len)
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
