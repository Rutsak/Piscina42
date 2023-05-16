/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:58:44 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:03 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int		i;
	char					*rs1;
	char					*rs2;

	i = 0;
	rs1 = (void *)s1;
	rs2 = (void *)s2;
	if (n == 0)
		return (0);
	else
	{
		while (i <= n)
		{
			if (rs1[i] == rs2[i])
				i++;
			else
				return (rs1[i] - rs2[i]);
		}
	}
	return (0);
}
