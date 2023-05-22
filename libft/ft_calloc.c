/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:26:19 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:05 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*mem;
	size_t		i;
	
	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, (count * size));
/*	else
	{
		while (i < (count * size))
		{
			(char *)mem [i] = 0;
			i++;
		}
	}*/
	return (mem);
}

/*int main(void)
{
	ft_calloc(2,3);
	return(0);
}*/
