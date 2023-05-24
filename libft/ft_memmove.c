/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:40 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/24 15:47:36 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long int	i;
	unsigned char		*strsrc;
	unsigned char		*strdst;

	i = 0;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	if(!strsrc && !strdst)
		return (NULL);
	if	(strsrc > strdst)
	{
		while (i != len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i != 0)
		{
			strdst[i - 1] = strsrc[i - 1];
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

