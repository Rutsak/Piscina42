/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:46:42 by doller-m          #+#    #+#             */
/*   Updated: 2023/07/12 17:34:30 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static unsigned char	*str_gen(unsigned int start, size_t fin)
{
	unsigned char	*str;

	if ((int)fin - (int)start > 0)
		str = (unsigned char *)malloc(fin - start + 1);
	else
		str = (unsigned char *)malloc(1);
	if (!str)
		return (0);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned char	*str;
	size_t			fin;

	i = 0 - 1;
	if (start > ft_strlen((char *)s))
	{
		str = (unsigned char *)malloc(1);
		if (!str)
			return (0);
		return ((char *)str);
	}
	if (start + len < ft_strlen((char *)s))
		fin = start + len;
	else
		fin = ft_strlen((char *)s);
	str = str_gen(start, fin);
	if (str == 0)
		return (0);
	if (start >= ft_strlen((char *)s))
		return ((char *)str);
	while (++i < fin - start)
		str[i] = s[i + start];
	str[i] = '\0';
	return ((char *)str);
}

/* void	freemem(char *str)
{

} */

char	*analisis(char **str_work)
{
	char	*end_line;
	char	*str_return;
	char	*erase;
	size_t	workreturn_len;
	size_t	return_len;

	end_line = ft_strchr (*str_work, '\n');
	if (end_line == 0)
		end_line = ft_strchr (*str_work, '\0');
	return_len = (&end_line[0] - &*str_work[0]) + 1;
	workreturn_len = (ft_strlen(*str_work)) - return_len;
	if (end_line == 0)
		return (NULL);
	str_return = ft_substr(*str_work, 0, return_len);
	if (!str_return)
		return (NULL);
	erase = *str_work;
	*str_work = ft_substr(*str_work, return_len, workreturn_len);
	if (!str_work)
		return (NULL);
	free (erase);
	return (str_return);
}

char	*get_next_line(int fd)
{
	static char	*str_work;
	char		*str_return;
	char		buffer[BUFFER_SIZE];
	int			read_status;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!str_work)
	{
		read_status = read (fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		str_work = gnl_strjoin (str_work, buffer);
		if (!str_work)
			return (NULL);
	}
	if (str_work[0] == '\0' && read_status == 0)
	{
		free(str_work);
		return (NULL);
	}
	str_return = analisis(&str_work);
	while (str_return == 0 && read_status != 0)
	{
		read_status = read (fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		str_work = gnl_strjoin (str_work, buffer);
		str_return = analisis(&str_work);
	}
	return (str_return);
}
