/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:11:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/19 09:22:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "util.h"
# include "node_list.h"
# include "ft_boolean.h"

typedef struct map_attributes
{
	int		x_map;
	int		y_map;
	char	empty;
	char	obstacle;
	char	full;
	t_nlist nlist;
} t_map;

char	*get_file_content(char *filepath, int count);
char	*read_file_content(char *filepath);
t_bool	check_not_repeat(t_map *map);
t_bool	check_printable(t_map *map);
t_bool check_first_line_cond(t_map *map);
t_bool	check_first_line(char **content, t_map *map);
int	get_len_x(char *content);
t_bool	get_obstacle_coord(char *content, t_map *map);
t_bool	check_map_body(char *content, t_map *map);
t_map	*get_map_attributes(char	*filepath);

#endif
