/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:53:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/05/02 17:22:54 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>*/

int	ft_isacii(char c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int main(void)
{
    char    c;
    int     ret;
    c = 'a';

    ret = ft_isacii(c);
    printf("%i",ret);
}*/