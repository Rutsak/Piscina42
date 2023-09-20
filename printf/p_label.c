/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:20:27 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/20 15:06:21 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	printchar(char *c)
{
	int	write_status;

	write_status = write(1, c, 1);
	return (write_status);
}

char	hexa_char(int num)
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
}

int	hexa_print(unsigned long long nbr)
{
	int					character;
	int					i = 0;
	char				a;

	if (nbr > 0)
	{
		character = nbr % 16;
		a = hexa_char(character);
		nbr = nbr/16;
		i = i + 1 + hexa_print(nbr);
		printchar (&a);
	}
	return (i);
}

int	p_label(char *pointer)
{
	int						i;
	unsigned long long		nbr;

	i = 0;
	printchar ("0");
	printchar ("x");
	nbr = (unsigned long long)pointer;
	i = 2 + hexa_print(nbr);
	return (i);
}
int	main(void)
{
	char	*a;
	int		impr;

	a = "Hola";
	impr = p_label(a);
	printf("\nCaracters impresos = %i", impr);
	return (0);
}