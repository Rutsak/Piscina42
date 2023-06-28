/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovoa <anovoa@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:15:15 by anovoa            #+#    #+#             */
/*   Updated: 2023/04/15 22:28:03 by anovoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	ft_check_argc(argc, argv);
	printf("Test\nEste es tu input: %u",ft_atoi(argv[1]));
	return (0);
}
