/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:56:21 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/18 13:08:57 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char				*str;
	size_t				i;

	str = (char *)s;
	i = 0;
	if (n == 0)
		i = 0;
	else
	{
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
}

/*int	main(void)
{
	char	*a;
	size_t	n;
	char str[] = "Hola";

	n = 4;
	printf ("%s", str);
	ft_bzero (str,n);
	printf ("%d\n", str[0]);
	printf ("%d\n", str[1]);
	printf ("%d\n", str[2]);
	printf ("%d\n", str[3]);
	return (0);
}*/
