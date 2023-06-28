/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:30:54 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/11 20:32:46 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int m;
	int	c;
	int	d;
	int	u;

	m = 0;
	c = 0;
	d = 0;
	u = 0;

	while (c <= 9)
	{
		if (u >= 9)
		{
			d++;
			u = 0;
			if(d >= 9)
			{
				c++;
				d = 0;
				if(c >= 9)	
				{
					c = 11;
				}
			}
		}
		else
		u++;
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
				;
		}
	}
}

		
int main(void)
{
	ft_print_comb2();
	return (0);
}
