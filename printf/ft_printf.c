/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/28 16:05:35 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	printchar(char *c)
{
	int	write_status;

	write_status = write(1, c, 1);
	return (write_status);
}
/* 
int	string_print(char *a, int position)
{
	int	i;

	i = 0;

	while (a[position + i] != '\0')
	{
		if (a[0] == '%')
		{
			return (i);
		}
		printchar(&a[i]);
		i++;
	}
	return (1);
} */

int	wall_ifs(char label, char *str)
{
	int	len;

	len = 0;
	if (label == 'c')
		len = c_label(str);
	else if (label == 's')
		len = s_label(str);
	else if (label == 'p')
		len = p_label(str);
	else if (label == 'd')
		len = 0;
	else if (label == 'i')
		len = i_label((int) str);
	else if (label == 'u')
		len = 0;
	else if (label == 'x')
		len = 0;
	else if (label == 'X')
		len = 0;
	else if (label == '%')
		len = percent_label();
	return (len);
}

int	ft_printf(const char *a,...)
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
			temp = wall_ifs(str[0], va_arg(var, char *));
		}
		else
			temp = printchar(str);
		if (temp == -1)
			return (temp);
		len += temp;
		str++;
	}
	va_end(var);
	return (len);
}

/* int	ft_printf(const char *a,...)
{
	int			*prt_chr;
	int			*lb_char_cnt;
	int			*error_flag;
	va_list		var;

	va_start (var, a);
	*prt_chr = 0;
	*lb_char_cnt = 0;
	*error_flag = 0;
	while (a[*prt_chr - (*lb_char_cnt * 2)] != '\0' && *error_flag == 0)
	{
		if (a[*prt_chr - (*lb_char_cnt * 2)] == '%')
		{
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'c')
				*prt_chr += printchar(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 's')
				*prt_chr += s_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'p')
				*prt_chr += p_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'd')
				*prt_chr += d_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'i')
				*prt_chr += i_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'u')
				*prt_chr += u_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'x')
				*prt_chr += x_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == 'X')
				*prt_chr += X_label(va_arg(var, char *));
			if (a[*prt_chr - (*lb_char_cnt * 2) +1] == '%')
				*prt_chr += percent_label(va_arg(var, char *));
			*lb_char_cnt++;
		}
		else
			*prt_chr += string_print(a, *prt_chr - (*lb_char_cnt * 2));
	}
	va_end(var);
	return (*prt_chr);
} */
/* int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	int		len;

	a = "%%";
	b = "yaa";
	c = "zaa";
	len = ft_printf(a, b, c);
	printf("\nResultat %i", len);
	return (0);
}
 */