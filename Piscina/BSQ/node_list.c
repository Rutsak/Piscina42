/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:21:43 by junghwle          #+#    #+#             */
/*   Updated: 2023/04/18 19:43:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_list.h"

/*
typedef char	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct node_list
{
	t_node	*arr;
	int		curr_len;
	int		max_len;
}t_nlist;

typedef struct node
{
	int	x;
	int	y;
}t_node
*/

int	add_value(t_nlist *nlist, int x, int y)
{
	if (nlist->curr_len == nlist->max_len)
	{
		if (increase_nlist_size(nlist) == -1)
			return (-1);
	}
	nlist->arr[nlist->curr_len].x = x;
	nlist->arr[nlist->curr_len].y = y;
	nlist->curr_len++;
	return (0);
}

/*INI_NLEN 10*/
t_nlist	create_nlist(int size)
{
	t_nlist	nlist;
	int		i;

	i = 0;
	nlist.curr_len = 0;
	nlist.max_len = size;
	nlist.arr = (t_node *)malloc(sizeof(t_node) * nlist.max_len);
	if (nlist.arr == NULL)
		nlist.max_len = -1;
	while (i < nlist.max_len)
	{
		nlist.arr[i].x = -1;
		nlist.arr[i].y = -1;
		i++;
	}
	return (nlist);
}

int	n_arrcpy(t_node *dest, t_node *src, int dest_len, int src_len)
{
	int	i;

	if (dest == NULL || src == NULL)
		return (-1);
	i = 0;
	while (i < src_len)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
		i++;
	}
	while (i < dest_len)
	{
		dest[i].x = -1;
		dest[i].y = -1;
		i++;
	}
	return (0);
}

/*MAX_NLEN_STEP 80*/
int	increase_nlist_size(t_nlist	*nlist)
{
	int		new_len;
	t_node	*new_arr;
	int		i;

	if (nlist->max_len <= MAX_NLEN_STEP)
		new_len = nlist->max_len * 2;
	else
		new_len = nlist->max_len + MAX_NLEN_STEP;
	i = 0;
	new_arr = (t_node *)malloc(sizeof(t_node) * new_len);
	if (new_arr != NULL)
	{
		n_arrcpy(new_arr, nlist->arr, new_len, nlist->max_len);
		free(nlist->arr);
		nlist->max_len = new_len;
		nlist->arr = new_arr;
		return (0);
	}
	else
		return (-1);
}
