/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:07:35 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/01 17:55:42 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strlen no incluye el '\0'*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resul;
	int		i;
	int		ls1;
	int		ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	resul = malloc(ls1 + ls2 + 1);
	if (!resul)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		resul[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		resul[ls1 + i] = s2[i];
		i++;
	}
	resul[ls1 + i] = '\0';
	return (resul);
}
/*
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main (void)
{
	char	*result;
	char	*s1 = "lorem ipsum";
	char	*s2 = "dolor sit amet";

	result = ft_strjoin(s1, s2);
	printf("%s", result);
	return (0);
}
*/