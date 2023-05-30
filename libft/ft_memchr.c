/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:26:44 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/30 13:13:50 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((str[i]) != (char)c)
		{
			i++;
		}
		else if ((str[i]) == (char)c)
			return (&str[i]);
		else
			return (NULL);
	}
	return (NULL);
}

/*
int main(void)
{
	void	*a;
	char	*s = "bonjour";
	int		c = 'j';
	size_t	n = 6;

	a = ft_memchrs(s, c, n);
	printf("FT = %s '\n'", a);
	a = memchrs(s, c, n);
	printf("FT = %s '\n'", a);
}*/
