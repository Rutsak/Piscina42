/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:35:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/19 10:32:28 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	if (len == 0)
		return (b);
	else
	{
		while ((len) != 0)
		{
			(str[len - 1]) = (unsigned char)c;
			len--;
		}
	}
	return (b);
}

/*int	main(void)
{
	char	a[10];
	void	*b;


	b = ft_memset(a, 'A', 20);
	printf("%s", a);
	return (0);
}*/