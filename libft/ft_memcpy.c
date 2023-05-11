/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:18:59 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/11 13:04:10 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	while ((n - 1) >= 0)
	{
		(strdst[n - 1]) = (strsrc[n - 1]);
		n--;
	}
	return (dst);
}
