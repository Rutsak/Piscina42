/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:25:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/09 19:28:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

void	putint(int num)
{
	int	div;

	if (num < 0)
	{
		putchar('-');
		num *= -1;
	}
	div = 1;
	while (div * 10 <= num)
		div *= 10;
	while (div > 0)
	{
		putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}
}
