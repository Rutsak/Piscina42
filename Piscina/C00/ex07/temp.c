/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:18 by doller-m          #+#    #+#             */
/*   Updated: 2023/04/12 16:46:19 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	potencia10(int x)
{
	int i;
	int result;

	result = 1;
	i = 1;
	while(i < x)
	{
		result = result * 10;
		i++;
	}
	return(result);
}


void ft_putnbr(int nb)
{
	int loop;
	int digit;
	int nb_rest;
	int print;

	nb_rest = nb;
	loop = 10;
	if(nb < 0)
	{
		write(1, "-", 1);
		nb_rest = nb * (-1);
	}
	while(loop > 0)
	{
		digit = (nb_rest / potencia10(loop));
		print = digit +'0';
		write(1, &print, 1);
		nb_rest = nb_rest - (digit * potencia10(loop));
		loop--;
	}
}	


int main(void)
{
	ft_putnbr(147483647);
}
