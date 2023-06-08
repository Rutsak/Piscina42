/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:04:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/06 14:59:35 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		f;
	int		r;
	int		i;
	int		strl;

	f = 0;
	i = 0;
	strl = ft_strlen((char *)s1);
	r = strl;
	while (s1[f] != 0 && ft_strchr(set, s1[f]) != 0)
		f++;
/* 	if (ft_strlen((char *)set) == 0)
	{
		str = (char *) malloc ((sizeof (char)) * (strl + 1));
		if (!str)
			return (0);
		while (i < (r - f + 1))
		{
			str[i] = s1[f + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	if (r == f)
		return (0);
		return (str = (char *) malloc ((sizeof (char)) * 1)); */
	while (r > f && ft_strchr(set, s1[r]) != 0)
		r--;
	str = (char *) malloc ((sizeof (char)) * (r - f + 2));
	if (!str)
		return (0);
	while (i < (r - f + 1))
	{
		str[i] = s1[f + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		else
			i++;
	}
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (0);
}

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
int main(void)
{
	char const	*a;
	char const	*s1;
	char const	*set;

	s1 = "";
	set = " \n\t";
	a = ft_strtrim(s1, set);
	printf("La string original es: %s\n", s1);
	printf("El set es: %s\n", set);
	printf("La string resultante es: %s\n", a);
} */