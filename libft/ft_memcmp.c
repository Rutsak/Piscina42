/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:58:44 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/30 11:23:56 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*rs1;
	unsigned char	*rs2;

	i = 0;
	rs1 = (void *)s1;
	rs2 = (void *)s2;
	if (n == 0)
		return (0);
	else
	{
		while (i <= n - 1) 
		{
			if (rs1[i] == rs2[i])
				i++;
			else
				return (rs1[i] - rs2[i]);
		}
	}
	return (0);
}
/*
#include <string.h>

int	main(void)
{
	char	s1[] = "abcdefghij";
	char	s2[] = "abcdefgxyz";
	size_t	n = 7;
	int	a;
	
	a = ft_memcmp(s1, s2, n);
	printf("Resultat FT: %i \n", a);
	a = memcmp(s1, s2, n);
	printf("Resultat Origen: %i \n", a);
	return(0);
}*/
