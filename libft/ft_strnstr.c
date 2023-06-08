/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:06:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/30 18:15:18 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*aguja;
	char	*pajar;

	aguja = (char *)needle;
	pajar = (char *)haystack;
	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (aguja[0] == pajar[i])
		{
			j = 0;
			while (aguja[j] == pajar[i + j] && (i + j < len))
			{
				j++;
				if (aguja[j] == '\0')
					return (&pajar[i]);
				if (pajar[i] == '\0')
					return (0);
			}
		i++;
		}
	while (i < len && pajar[i] != 0)
	{
		if (aguja[0] != pajar[i])
			i++;
		else if (aguja[0] == pajar[i])
		{
			j = 0;
			while (aguja[j] == pajar[i + j] && (i + j < len))
			{
				j++;
				if (aguja[j] == '\0')
					return (&pajar[i]);
			}
		i++;
		}
	}
	return (0);
}
/*
#include <string.h>

int	main(void)
{
	char		*a;
	const char	*haystack = "lorem ipsum dolor sit amet";
	const char	*needle = "lorem";
	size_t		len = 15;
	a = 0;

	a = ft_strnstr(haystack, needle, len);
	printf("Resultat FT: %s \n", a);
	a = strnstr(haystack, needle, len);
	printf("Resultat Orifinal: %s \n", a);
	return(0);
}*/
