/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:40 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/25 11:08:44 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* Intentant estalviar la creaci'o de dos arrays

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long int	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if ((unsigned char *)src > (unsigned char *)dst)
	{
		while (i != len)
		{
			(unsigned char *)dst[i] = (unsigned char *)src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i != 0)
		{
			(unsigned char *)dst[i - 1] = (unsigned char *)src[i - 1];
			i--;
		}
	}
	return (dst);
}*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long int	i;
	unsigned char		*strsrc;

	i = 0;
	strsrc = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (strsrc > (unsigned char *)dst)
	{
		while (i != len)
		{
			((unsigned char *)dst)[i] = strsrc[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i != 0)
		{
			((unsigned char *)dst)[i - 1] = strsrc[i - 1];
			i--;
		}
	}
	return (dst);
}

/*#include <string.h>

int main(void)
{
    char str[] = "0123456";
    printf("original: %s\n", str);
    printf("destino: %s\n", str+ 1);
    printf("memmove: %s\n", memmove(str + 1, str, 2));
    char str2[] = "0123456";
    printf("original2: %s\n", str2);
    printf("destino2: %s\n", str2+ 1);
    printf("ft_memmove: %s\n", ft_memmove(str2 + 1, str2, 2));
    return 0;
}*/
