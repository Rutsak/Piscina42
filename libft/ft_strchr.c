/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:08:58 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/22 12:27:10 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		else
			i++;
	}
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (0);
}

/*int	main(void)
{
	char	src1 [10] = "abbbbbbbb";
	char	src2 [10] = "abbbbbbbb";
	char	*a;
	char	*b;

	a = ft_strchr(src1, 97);
	b = strchr(src2, 97);
	return (0);
}*/
