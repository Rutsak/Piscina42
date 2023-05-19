/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:04:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/18 12:54:48 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		f;
	int		r;
	int		i;

	f = 0;
	r = 0;
	i = 0;
	while (f <= ft_strlen(s1))
	{
		while (set[i] != '\0')
		{
			if (set[i] = s1[f])
				f++;
			else
				i++;
		}
	}
	i = 0;
	while (r <= ft_strlen(s1))
	{
		while (set[i] != '\0')
		{
			if (set[i] = s1[ft_strlen(s1)-i])
				r++;
			else
				j++;
		}
	}
}
