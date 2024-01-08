/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:09 by doller-m          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:30 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nochar_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == 45)
			{
				if (argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57)
					j++;
			}
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	repetition_check(char **argv)
{

// falta el long per fer mes correcte la comparaci'o
	int	i;
	int	j;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = i + 1;
		while (argv[k])
		{
			j = 0;
			while (argv[i][j] && argv[k][j])
			{
				if (argv[i][j] == argv[k][j])
					j++;
			}
			k++;
		}

	}
}

int	main(int argc, char **argv)
{
	int			a;
//	int			b;

	if (argc < 2)
		return (-1);
	a = nochar_check(argv);
	ft_printf("Resultat %i", a);
	return (0);
}
