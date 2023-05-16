/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:06:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 15:25:23 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*aguja;
	char	*pajar;

	aguja = (char *)needle;
	pajar = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (aguja[0] == pajar[i])
	{
		j = 0;
		while (aguja[j] == pajar[i + j])
		{
			j++;
			if (j == len)
			{
				return (&pajar[i]);
			}
		}
		i++;
	}
	return (0);
}
