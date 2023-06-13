/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:41:30 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/13 17:01:41 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el número ’n’ al file descriptor dado.*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = n + 48;
	write(fd, &c, 1);
}
/* 
int	main(void)
{
	ft_putnbr_fd(6, 1);
	return (0);
} */