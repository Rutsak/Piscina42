/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:46:08 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/25 17:37:52 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&str[i]);
	while (str[i] != (char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	src1 [20] = "teste";
	char	src2 [20] = "teste";
	char	*a;
	char	*b;

	a = ft_strrchr(src1, 'x');
	printf("a: %s \n", a);
	b = strrchr(src2, 'x');
	printf("b: %s \n", b);
	return (0);
}*/
