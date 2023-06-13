/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:47:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/13 12:44:36 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	n_leng(int n)
{
	int				i;
	unsigned int	num;

	if (n == 0)
		return (1);
	else if (n < 0)
	{
		num = n *(-1);
		i = 1;
	}
	else
	{
		num = n;
		i = 0;
	}
	while (num / 10 > 0)
	{
		num = (num / 10);
		i++;
	}
	return (i + 1);
}

char	*reserva(int len)
{
	char	*a;

	a = malloc ((sizeof (char)) * (len + 1));
	if (!a)
		return (0);
	a[len] = '\0';
	return (a);
}

char	*escriu(char *a, int len, int neg, unsigned int result)
{
	int				i;
	int				rest;

	i = 0;
	if (neg == 0)
	{
		while (i < len)
		{
			rest = result % 10;
			result = (result / 10);
			a[(len - 1) - i] = rest + 48;
			i++;
		}
	}
	if (neg == 1)
	{
		while (i < len - 1)
		{
			rest = result % 10;
			result = (result / 10);
			a[(len - 1) - i] = rest + 48;
			i++;
		}
	}
	return (a);
}

char	*ft_itoa(int n)
{
	unsigned int	result;
	char			*a;
	int				len;
	int				neg;

	len = n_leng(n);
	if (n < 0)
	{
		result = n *(-1);
		a = reserva(len);
		if (!a)
			return (0);
		a[0] = '-';
		neg = 1;
	}
	else
	{
		result = n;
		neg = 0;
		a = reserva(len);
		if (!a)
			return (0);
	}
	a = escriu(a, len, neg, result);
	return (a);
}
/* 
int	main(void)
{
	char	*a;
	int		n;

	n = -9;
	a = ft_itoa(n);
	printf("No original es %i '\n", n);
	printf("No resultant es %s '\n", a);
} */