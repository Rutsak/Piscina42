/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_label.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:01:39 by doller-m          #+#    #+#             */
/*   Updated: 2023/10/02 13:59:19 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	printchar(char c)
{
	int	write_status;

	write_status = write(1, &c, 1);
	return (write_status);
} */

int	c_label(char str)
{
	int	len;

	len = printchar(str);
	return (len);
}

/* int	main(void)
{
	char	*str;
	int	len;

	str ="a";
	len = c_label(str);
	printf ("\nLeng es %i", len);
	return (len);
} */