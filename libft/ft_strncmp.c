/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:25 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/30 12:54:45 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	unsigned char	*rs1;
	unsigned char	*rs2;

	i = 0;
	rs1 = (unsigned char *)s1;
	rs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		else if (rs1[i] == rs2[i])
			i++;
		else
			return (rs1[i] - rs2[i]);
	}
	return (rs1[i - 1] - rs2[i - 1]);
}
/*
#include <string.h>

int	main(void)
{
	char	s1[] = "abcdefgh";
	char	s2[] = "abcdwxyz";
	size_t	n = 4;
	int	a;
	
	a = ft_strncmp(s1, s2, n);
	printf("Resultat FT: %i \n", a);
	a = strncmp(s1, s2, n);
	printf("Resultat Origen: %i \n", a);
	return(0);
}*/
