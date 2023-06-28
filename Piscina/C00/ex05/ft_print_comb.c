/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:48:55 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/12 12:35:22 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check(int c, int d, int u)
{
	if (u != d && u != c && d != c && u > d && d > c)
	{
		ft_putchar(c + '0');
		ft_putchar(d + '0');
		ft_putchar(u + '0');
		if (!(u == 9 && d == 8 && c == 7))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		else
			c = 100000;
	}
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = 0;
	d = 0;
	u = 0;
	while (c <= 9)
	{
		while (d <= 9)
		{
			while (u < 9)
			{
				u ++;
				check(c, d, u);
			}
			d ++;
			u = 0;
			check(c, d, u);
		}
		c ++;
		d = 0;
	}
}
