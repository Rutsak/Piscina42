/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:46:08 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/19 15:30:05 by doller-m         ###   ########.fr       */
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
	{
		i++;
	}
	while (str[i] != c)
	{
		i--;
	}
	if (i >= 0)
		return (&str[i]);
	else
		return (0);
}

/*int	main(void)
{
	char	src1 [10] = "abbbbbbbb";
	char	src2 [10] = "abbbbbbbb";
	char	*a;
	char	*b;

	a = ft_strrchr(src1, 97);
	b = strrchr(src2, 97);
	return (0);
}*/