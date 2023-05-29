/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:25 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/25 18:15:13 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*rs1;
	char	*rs2;

	i = 0;
	rs1 = (char *)s1;
	rs2 = (char *)s2;
	while (i <= n)
	{
		if (rs1[i] == rs2[i])
			i++;
		else
			return (rs1[i] - rs2[i]);
	}
	return (rs1[0] - rs2[0]);
}
