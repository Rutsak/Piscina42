/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:52:53 by anovoa            #+#    #+#             */
/*   Updated: 2023/04/16 14:15:29 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdlib.h>

int	ft_count_nospace(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{	
		if (!(*str == 32 || (*str >= 9 && *str <= 13)))
		{
			i++;
		}
		str++;
	}
	return (i);
}

char	*ft_remove_spaces(char *str)
{
	int		index;
	char	*output;

	index = 0;
	output = (char *)malloc(ft_count_nospace(str) * 1 + 1);
	if (output == NULL)
	{
		ft_puterror();
		return (str);
	}
	while (str[index])
	{
		if (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		else
		{
			output[index] = *str;
			index++;
		}
	}
	output[index] = '\0';
	return (output);
}
