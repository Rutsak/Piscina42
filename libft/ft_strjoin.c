/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:07:35 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/18 12:53:17 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		is1;
	int		is2;
	char	*strwork;
	char	*resul;

	is1 = ft_strlen((char *)s1);
	is2 = ft_strlen((char *)s2);
	resul = malloc(is1 + is2 + 1);
	if (!resul)
		return (NULL);
	else
	{
		strwork = (char *)s1;
		ft_strlcpy(resul, strwork, is1);
		strwork = (char *)s2;
		ft_strlcpy(&resul[is1], strwork, is2);
	}
	return (resul);
}

/*int main (void)
{
	char	*result;
	char	*s1 = "Hola ";
	char	*s2 = "mundo";

	result = ft_strjoin(s1, s2);
	printf("%s", result);
	return (0);
}
*/
