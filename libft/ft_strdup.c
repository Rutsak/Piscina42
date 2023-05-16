/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:12:33 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/16 15:28:10 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strdup(const char *s1)
{
	char	*mem;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	mem = (char *)malloc(i + 1);
	if (!mem)
		return (0);
	else
	{
		while (i >= 0)
		{
			mem [i] = s1[i];
			i--;
		}
	}
	return (mem);
}

/*int main(void)
{
	char	*a;

	a = strdup("Hola que ase");
}*/
