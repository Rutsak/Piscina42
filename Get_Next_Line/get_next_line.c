/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:42 by doller-m          #+#    #+#             */
/*   Updated: 2023/09/05 13:07:59 by doller-m         ###   ########.fr       */
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

/* char	*gnl_strwork_gen(char ***str_work, char **erase, char **str_return)
{
	**str_work = NULL;
	free (&erase);
	return (&str_return);
} */

char	*analisis(char **str_work)
{
	char	*end_line;
	char	*str_return;
	char	*erase;
	size_t	workreturn_len;
	size_t	return_len;

	end_line = ft_strchr(*str_work, '\n');
	if (end_line == 0)
		return (NULL);
	return_len = (&end_line[0] - &*str_work[0]) + 1;
	workreturn_len = (ft_strlen(*str_work)) - return_len;
	str_return = ft_substr(*str_work, 0, return_len);
	if (!str_return)
		return (NULL);
	erase = *str_work;
	if (workreturn_len == 0)
	{
		*str_work = NULL;
		free (erase);
		return (str_return);
	}
	else
		*str_work = ft_substr(*str_work, return_len, workreturn_len);
	if (!str_work)
		return (gnl_free(&erase));
	free (erase);
	return (str_return);
}

char	*read_end_str_return(char **str_return, char **str_work, char **buffer)
{
	*str_return = analisis(str_work);
	free (*buffer);
	if (!*str_return)
	{
		str_return = str_work;
		*str_work = (char *)malloc(1);
		if (!str_work)
			return (gnl_free(str_work));
		gnl_free(str_work);
		return (*str_return);
	}
	return (*str_return);
}

char	*get_next_line(int fd)
{
	static char	*str_work;
	char		*str_return;
	char		*buffer;
	int			read_status;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	str_return = 0;
	while (str_return == 0)
	{
		read_status = read (fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			free (buffer);
			return (gnl_free(&str_work));
		}
		if (read_status == 0)
		{
		return (read_end_str_return(&str_return, &str_work, &buffer));
/* 			str_return = analisis(&str_work);
			free (buffer);
			if (!str_return)
			{
				str_return = str_work;
				str_work = (char *)malloc(1);
				if (!str_work)
					return (gnl_free(&str_return));
				gnl_free(&str_work);
				return (str_return);
			}
			return (str_return); */
		}
		buffer[read_status] = '\0';
		str_work = gnl_strjoin (str_work, buffer);
		if (!str_work)
			return (gnl_free(&buffer));
		str_return = analisis(&str_work);
	}
	free(buffer);
	return (str_return);
}
