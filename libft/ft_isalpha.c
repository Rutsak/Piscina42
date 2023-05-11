/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:19 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/09 13:10:54 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_isalpha(char c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int main(void)
{
    char    c;
    int     ret;

    c = 'a';
    ret = ft_isalpha(c);
    printf ("%i", ret);
}*/