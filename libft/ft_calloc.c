/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:26:19 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/11 17:42:34 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void *calloc(size_t count, size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char *)malloc(count * size);
	if (!mem)
		return (0);
	else
	{
		while (i < (int)(count * size))
		{
			mem [i] = '0';
			i++;
		}
	}
	return ((void*)mem);
}

int main(void)
{
	calloc(2,3);
	return(0);
}
