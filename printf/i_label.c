/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:26 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 13:25:26 by doller-m         ###   ########.fr       */
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

int	digit(unsigned int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	descompon(unsigned int n, int pos, int len)
{
	char	a;

	while (len != pos)
	{
		a = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (a);
}

int	i_label(int n)
{
	int				i;
	char			a;
	int				len;
	unsigned int	n_unsign;

	if (n < 0)
	{
		n_unsign = n * (-1);
		printchar('-');
	}
	else
		n_unsign = n;
	len = digit(n_unsign);
	i = 0;
	while (i != len)
	{
		a = descompon(n_unsign, i, len);
		printchar(a);
		i++;
	}
	return (i);
}
/* 
int	main(void)
{
	int	i = -856;

	i_label(i);
	return (0);
} */