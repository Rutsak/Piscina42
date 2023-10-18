/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:41:30 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/14 13:16:27 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el número ’n’ al file descriptor dado.*/

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	char			a;
	int				len;
	unsigned int	n_unsign;

	if (n < 0)
	{
		n_unsign = n * (-1);
		write(fd, "-", 1);
	}
	else
		n_unsign = n;
	len = digit(n_unsign);
	i = 0;
	while (i != len)
	{
		a = descompon(n_unsign, i, len);
		write(fd, &a, 1);
		i++;
	}
}
/* 
int	main(void)
{
	ft_putnbr_fd(-5, 1);
	return (0);
} */