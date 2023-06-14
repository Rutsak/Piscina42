/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:15:59 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/14 11:52:37 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A cada carácter de la string ’s’, aplica la función ’f’ dando como 
parámetros el índice de cada carácter dentro de ’s’ y el propio carácter.
Genera una nueva string con el resultado del uso sucesivo de ’f’ */
#include "libft.h"

char	*reserva(int len)
{
	char	*a;

	a = malloc ((sizeof (char)) * (len + 1));
	if (!a)
		return (0);
	a[len] = '\0';
	return (a);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		i;
	char		*s_transf;

	len = ft_strlen((char *)s);
	s_transf = reserva(len);
	if (!s_transf)
		return (0);
	i = 0;
	while (i < len)
	{
		s_transf[i] = f(i, s[i]);
		i++;
	}
	return (s_transf);
}
