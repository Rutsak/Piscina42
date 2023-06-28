/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:08:11 by anovoa            #+#    #+#             */
/*   Updated: 2023/04/16 05:10:06 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_valid_input(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_is_valid_dict(char *str)
{
	while (*str)
	{
		str++;
	}
	return (0);
}

void	ft_check_argc(int argc, char *argv[])
{
	if (argc == 2 && ft_is_valid_input(argv[1]) == 1)
	{
		ft_read_local_dict();
	}
	else if (argc == 3 && ft_is_valid_input(argv[2]) == 1)
	{
		if (ft_is_valid_dict(argv[1]))
			ft_read_local_dict();
		else
			ft_putdict_error();
	}
	else
		ft_puterror();
}
