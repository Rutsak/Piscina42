/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/18 14:51:21 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	printchar(char *c)
{
	int	write_status;

	write_status = write(1, c, 1);
	return (write_status);
}

int	ft_printf(const char *a,...)
{
	char		*test;
	va_list		var;
	va_start	(var, a);

	test = (char *)a;
	//printchar((char *)a);
	// test = va_arg(var, char *);
	while (test)
	{
		printchar(test);
		test = va_arg(var, char *);
	}
	va_end(var);
	return (1);
}
/* int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = "xaa";
	b = "yaa";
	c = "zaa";
	ft_printf(a, b, c);
	return (0);
} */
