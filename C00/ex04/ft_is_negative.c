/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:50:20 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/11 12:50:26 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

int	ft_is_negative(void)
{
	int	c;

	c = -16510;
	if (c < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
	return (0);
}
