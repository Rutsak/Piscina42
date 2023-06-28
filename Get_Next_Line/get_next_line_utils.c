/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:02 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/27 13:21:18 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != (char) c)
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static void	s1_result(char const *s1, char *resul)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		resul[i] = s1[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*resul;
	int		i;
	int		ls1;
	int		ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	resul = malloc(ls1 + ls2 + 1);
	if (!resul)
		return (NULL);
	s1_result(s1, resul);
	i = 0;
	while (s2[i] != '\0')
	{
		resul[ls1 + i] = s2[i];
		i++;
	}
	resul[ls1 + i] = '\0';
	free(s1);
	free(s2);
	return (resul);
}