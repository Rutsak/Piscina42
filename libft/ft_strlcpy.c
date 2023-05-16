/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:25:56 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:52 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long int	l;

	l = 0;
	if (dstsize == 0)
		return (l);
	else
	{
		while (l != dstsize)
		{
			dst[l] = src[l];
			l++;
		}
	dst[l] = '\0';
	}
	return (l);
}
