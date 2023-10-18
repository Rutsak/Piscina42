/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:08:08 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/05 14:22:04 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	hexa_print_x(unsigned int nbr, char label)
{
	int				character;
	int				i;
	char			a;
	int				error_check;

	i = 0;
	if (nbr > 0)
	{
		character = nbr % 16;
		a = hexa_char(character);
		nbr = nbr / 16;
		error_check = hexa_print_x(nbr, label);
		if (error_check == -1)
			return (-1);
		i = i + 1 + error_check;
		if (label == 'X' && a >= 97 && a <= 102)
			error_check = printchar (a - 32);
		else
			error_check = printchar (a);
		if (error_check == -1)
			return (error_check);
	}
	return (i);
}

int	x_label(unsigned int str, char label)
{
	int	i;
	int	error_check;

	i = 0;
	if (str == 0)
	{
		error_check = write(1, "0", 1);
		return (error_check);
	}
	i = hexa_print_x(str, label);
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