/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:02:37 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/22 16:25:45 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long int	i;
	unsigned char		*str;
	unsigned char		*scopy;

	scopy = (unsigned char *)s;
	i = 0;
	str = (unsigned char *)ft_calloc(1, len + 1);
	if (!str)
		return (0);
	while (i < start)
	{
		if (scopy[i] != '\n')
			i++;
		else
			return (0);
	}
	while (len > 0)
	{
		scopy[i + len] = str [len];
		len--;
	}
	return ((char *)str);
}

/*int	main(void)
{
	char			*a;
	char			*s;
	unsigned int	start;
	size_t			len;

	s = "i just want this part #############";
	start = 0;
	len = 22;
	a = ft_substr(s, start, len);
	printf("%s", a);
}*/
