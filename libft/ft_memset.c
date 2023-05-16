/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:35:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 15:28:35 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while ((len - 1) >= 0)
	{
		(str[len - 1]) = c + '0';
		len--;
	}
	return (b);
}
