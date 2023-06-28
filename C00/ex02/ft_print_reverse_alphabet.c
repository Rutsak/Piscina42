/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:51:06 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/11 12:51:14 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c != 'a')
	{
		write (1, &c, 1);
		c--;
	}
	return (0);
}
