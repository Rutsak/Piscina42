/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:21:50 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/18 20:53:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_LIST_H
# define NODE_LIST_H
# include <stdlib.h>
# include "ft_boolean.h"
# define MAX_NLEN_STEP 80

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

/*node_list.c*/
int		add_value(t_nlist *nlist, int x, int y);
t_nlist	create_nlist(int size);
int		n_arrcpy(t_node *dest, t_node *src, int dest_len, int src_len);
int		increase_nlist_size(t_nlist *nlist);
void	print_list(t_nlist nlist);

/*node_list2.c*/
t_nlist	get_range_nlist(t_nlist nlist, int xs, int ys, int lens);
int		get_min_range_index(t_nlist nlist, int xs, int ys, int len_s);
int		get_max_range_index(t_nlist nlist, int xs, int ys, int len_s);
#endif
