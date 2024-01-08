/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:22:50 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/13 16:23:41 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Envía el carácter ’c’ al file descriptor especificado.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
