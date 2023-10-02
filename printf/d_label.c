/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:52:27 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 15:23:14 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* int	printchar(char *c)
{
	int	write_status;

	write_status = write(1, c, 1);
	return (write_status);
} */

int	d_label(double n)
{
	int		i;
	int		test;
	double	test1;

	i = 0;
	if (n == 0)
		return (1);
	test = (int) n;
	test1 = n - (double)test;
	if (n / test != 1)
		i = 1;
	while (n / test != 1)
	{
		n = n * 10;
		test = (int) n;
		i++;
	}
	return (i);
}
/* 
int	main(void)
{
	double	n;
	int		i;

	n = 1.234;
	i = d_label(n);
	printf("valor de N: %f \n", n);
	printf("valor de i: %i \n", i);
	return (i);
} */