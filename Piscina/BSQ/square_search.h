/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_search.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:54:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/17 19:12:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_SEARCH_H
# define SQUARE_SEARCH_H
# include "map.h"

/*
typedef struct node
{
	int	x;
	int	y;
}t_node;

typedef struct node_list
{
	t_node	*arr;
	int		curr_len;
	int		max_len;
}t_nlist;
*/
t_bool	check_obstacle(t_nlist nlist, int x, int y, int n);
t_node	*check_square(t_map map, int n);
int		checkmax(long long int libres, int x_map, int y_map);
int		get_obstacle_p(long long int libres, int map_length);
void	draw_map(t_map map, t_node node, int n);
#endif
