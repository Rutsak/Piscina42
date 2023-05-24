/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:26:44 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/24 14:11:13 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	while (i <= n - 1)
	{
		if ((str[i]) != c)
		{
			i++;
		}
		else if ((str[i]) != c)
			return (&str[i]);
		else
			return (0);
	}
	return (0);
}
