/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:17:12 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/23 15:29:24 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_lst;
	t_list	*temp_node;
	t_list	*nw_node;

	nw_lst = 0;
	nw_node = 0;
	if (lst && f && del)
	{
		while (lst)
		{
			nw_node = f(lst->content);
			temp_node = ft_lstnew(nw_node);
			if (temp_node == 0)
			{
				ft_lstclear(&lst, del);
				free(nw_node);
				return (0);
			}
			ft_lstadd_back(&nw_lst, temp_node);
			temp_node = temp_node->next;
			lst = lst->next;
		}
		free(nw_node);
		return (nw_lst);
	}
	return (0);
}
