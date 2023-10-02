/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:08:08 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 17:42:47 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* #include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	printchar(char *c)
{
	int	write_status;

	write_status = write(1, c, 1);
	return (write_status);
} */

/* char	hexa_char(int num)
{
	char	a;

	a = num + 48;
	if (num < 10)
		return (a);
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	return (0);
}*/

int	hexa_print_x(int nbr, char label)
{
	int					character;
	int					i;
	char				a;

	i = 0;
	if (nbr > 0)
	{
		character = nbr % 16;
		a = hexa_char(character);
		nbr = nbr / 16;
		i = i + 1 + hexa_print(nbr);
		if (label == 'x')
			printchar (a);
		if (label == 'X')
			printchar (a + 32);
	}
	return (i);
}

int	x_label(int str, char label)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = (int)str;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	i = hexa_print_x(nbr, label);
	return (i);
}
/* int	main(void)
{
	char	*a;
	int		impr;

	a = "Hola";
	impr = x_label(a);
	printf("\nCaracters impresos = %i", impr);
	return (0);
} */