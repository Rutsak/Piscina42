/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:06:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/20 12:05:39 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	flag(char *aguja, char *pajar, size_t i, size_t len)
{
	size_t	j;	

	j = 0;
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
					return (1);
			}
		i++;
		}
	}
	return (-1);
}

size_t	loop_inici(char *aguja, char *pajar, size_t i, size_t len)
{
	size_t	j;

	if (aguja[0] == pajar[i])
	{
		j = 0;
		while (aguja[j] == pajar[i + j] && (i + j < len))
		{
			j++;
			if (aguja[j] == '\0')
				return (i);
			if (pajar[i] == '\0')
				return (0);
		}
		i++;
	}
	return (0);
}

size_t	loop_2(char *aguja, char *pajar, size_t i, size_t len)
{
	size_t	j;	

	j = 0;
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
					return (i);
			}
		i++;
		}
	}
	return (0);
}

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
	if (flag(aguja, pajar, i, len) == -1)
		return (0);
	i = loop_inici(aguja, pajar, i, len);
	if (i > 0)
		return (&pajar[i]);
	i = loop_2(aguja, pajar, i, len);
	return (&pajar[i]);
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
}
 */