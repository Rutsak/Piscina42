/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 15:28:11 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	printchar(char c)
{
	int	write_status;

	write_status = write(1, &c, 1);
	return (write_status);
}

int	wall_ifs(char label, va_list va)
{
	int	len;

	len = 0;
	if (label == 'c')
		len = c_label((char)va_arg(va, int));
	else if (label == 's')
		len = s_label(va_arg(va, char *));
	else if (label == 'p')
		len = p_label(va_arg(va, char *));
	else if (label == 'd')
		len = i_label(va_arg(va, int));
	else if (label == 'i')
		len = i_label(va_arg(va, int));
	else if (label == 'u')
		len = i_label(va_arg(va, int));
	else if (label == 'x')
		len = p_label(va_arg(va, char *));
	else if (label == 'X')
		len = p_label(va_arg(va, char *));
	else if (label == '%')
		len = percent_label();
	return (len);
}

int	ft_printf(const char *a, ...)
{
	char		*str;
	int			len;
	int			temp;
	va_list		var;

	va_start (var, a);
	len = 0;
	str = (char *)a;
	while (str[0] != '\0')
	{
		if (str[0] == '%')
		{
			str++;
			temp = wall_ifs(str[0], var);
		}
		else
			temp = printchar(*str);
		if (temp == -1)
			return (temp);
		len += temp;
		str++;
	}
	va_end(var);
	return (len);
}
/* int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	int		len;

	a = "%c";
	b = "x";
	c = "zaa";
	len = ft_printf(a, b, c);
	printf("\nResultat %i", len);
	return (0);
} */
