/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:30:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/12 12:34:44 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check(int d, int u)
{
	if (d < u)
	{
		ft_putchar((d / 10) + '0');
		ft_putchar((d % 10) + '0');
		ft_putchar(' ');
		ft_putchar((u / 10) + '0');
		ft_putchar((u % 10) + '0');
		if (! (u == 99 && d == 98))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		else
			d = 100000;
	}
}

void	ft_print_comb2(void)
{
	int	d;
	int	u;

	d = 0;
	u = 0;
	while (d < 98)
	{
		if (u == 99)
		{
			d++;
			u = d + 1;
			check(d, u);
		}
		else
		{
			u++;
			check(d, u);
		}
	}
}
