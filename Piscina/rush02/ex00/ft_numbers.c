/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:57:29 by anovoa            #+#    #+#             */
/*   Updated: 2023/04/15 15:53:04 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}
