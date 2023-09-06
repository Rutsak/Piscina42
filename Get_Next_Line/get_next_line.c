/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:42 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/06 18:02:44 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*gnl_free(char **str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

char	*gnl_gen(char **str_work, char *line, size_t workr_len, size_t r_len)
{
	char	*erase;

	erase = *str_work;
	if (workr_len == 0)
	{
		*str_work = NULL;
		free (erase);
		return (line);
	}
	else
		*str_work = ft_substr(*str_work, r_len, workr_len);
	if (!str_work)
		return (gnl_free(&erase));
	free (erase);
	return (line);
	*str_work = NULL;
	free (&erase);
	return (line);
}

char	*analisis(char **str_work, int read_status)
{
	char	*end_line;
	char	*str_return;
	size_t	workreturn_len;
	size_t	return_len;

	end_line = ft_strchr(*str_work, '\n');
	if (end_line == 0)
		return (NULL);
	return_len = (&end_line[0] - &*str_work[0]) + 1;
	workreturn_len = (ft_strlen(*str_work)) - return_len;
	str_return = ft_substr(*str_work, 0, return_len);
	gnl_gen(str_work, str_return, workreturn_len, return_len);
	if (read_status == 0)
	{
		if (!str_return)
		{
			str_return = *str_work;
			*str_work = (char *)malloc(1);
			if (!str_work)
				return (gnl_free(&str_return));
			gnl_free(str_work);
			return (str_return);
		}
	}
	return (str_return);
}

int	read_gnl(char **str_work, int fd)
{
	char		*buffer;
	int			read_status;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	read_status = read (fd, buffer, BUFFER_SIZE);
	if (read_status == -1)
	{
		gnl_free(&buffer);
		return (-1);
	}
	buffer[read_status] = '\0';
	if (buffer[0] != '\0')
		*str_work = gnl_strjoin (*str_work, buffer);
	if (!str_work)
	{
		gnl_free(&buffer);
		return (-1);
	}
	gnl_free(&buffer);
	return (read_status);
}

char	*get_next_line(int fd)
{
	static char	*str_work;
	char		*str_return;
	int			read_status;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str_return = 0;
	while (str_return == 0)
	{
		read_status = read_gnl(&str_work, fd);
		if (read_status == -1)
			return (gnl_free(&str_work));
		str_return = analisis(&str_work, read_status);
/* 		if (read_status == 0)
		{
			if (!str_return)
			{
				str_return = str_work;
				str_work = (char *)malloc(1);
				if (!str_work)
					return (gnl_free(&str_return));
				gnl_free(&str_work);
				return (str_return);
			}
		} */
	}
	return (str_return);
}
