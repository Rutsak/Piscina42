/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:11 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/29 18:09:53 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lsrc;
	size_t	ldst;

	i = 0;
	while (src[i] != '\0')
		i++;
	lsrc = i;
	if (dstsize == 0)
		return (lsrc);
	i = 0;
	while (dst[i] != '\0')
		i++;
	ldst = i;
	i = 0;
	while ((ldst + i) < dstsize - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	while ((ldst + i) < dstsize)
	{
		dst[ldst + i] = '\0';
		i++;
	}
	if (ldst > dstsize)
		return (lsrc + dstsize);
	else
		return (ldst + lsrc);
}

/*
#include <string.h>

int main (void)
{
	size_t	a;
	size_t	b;
	char	src[30] = "lorem ipsum dolor sit amet";
	char	dst[30] = "a";
	size_t	dstsize;
	char	src1[30] = "lorem ipsum dolor sit amet";
	char	dst1[30] = "a";
	dstsize = 15;

	a = ft_strlcat(dst, src, dstsize);
	printf("El resultado del ft es: %zu \n", a);
	printf("La dst del ft es: %s \n", dst);
	b = strlcat(dst1, src1, dstsize);
	printf("El resultado del original es: %zu \n", b);
	printf("La dst del original es: %s \n", dst1);
	printf("La src del original es: %s \n", src1);
	return (0);
}
*/
