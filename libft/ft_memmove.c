/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:40 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/11 11:32:47 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*strsrc;
	unsigned char	*strdst;

	i = 0;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	while ((strdst[i]) != '\0')
		i++;
	if (i <= len)
		len = i;
	i = 0;
	while (strsrc[i] != '\0')
		i++;
	if (i <= len)
		len = i;
	while ((len - 1) >= 0)
	{
		(strdst[len - 1]) = (strsrc[len - 1]);
		len--;
	}
	return((void *)src);
}
