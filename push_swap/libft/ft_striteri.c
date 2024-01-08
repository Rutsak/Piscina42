/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:18:47 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/14 11:51:38 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como parámetros
el índice de cada carácter dentro de ’s’ y la dirección del propio carácter, que
podrá modificarse si es necesario.*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t		len;
	size_t		i;

	len = ft_strlen((char *)s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
