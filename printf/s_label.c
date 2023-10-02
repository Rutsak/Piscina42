/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:53:15 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 15:30:21 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_label(char *str)
{
	int	i;
	int	done;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			done = printchar(str[i]);
			if (done < 0)
				return (-1);
			i++;
		}
	}
	return (i);
}
