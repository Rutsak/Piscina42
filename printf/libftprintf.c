/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutsak <rutsak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:14:31 by rutsak            #+#    #+#             */
/*   Updated: 2023/08/21 10:01:29 by rutsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int ft_printf(char const *,...)
{
    va_list     a_list;
    va_start    (a_list,*);    
}

int printchar(int c)
{
    int write_status;

    write_status = write(1, c, 1);
    return (write_status)
}