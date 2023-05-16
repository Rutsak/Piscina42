/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:26:11 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 16:57:22 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long int	i;
	int					ldst;

	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	ldst = i + 1;
	i = 0;
	while (i < dstsize)
	{
		dst[ldst + i] = src[i];
		if (src[i] == '\0')
			return (ldst + i);
		else
			i++;
	}
	dst[ldst + i] = '\n';
	return (ldst + i);
}
