/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:17:12 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/22 17:14:54 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**nw_lst;
	t_list	*nw_node;

	nw_node = *ft_lstnew(*f);
	if (nw_node == 0)
		return (0);
	ft_lstadd_front(nw_lst, nw_node);
	while (lst)
		{
			ft_lstnew(*f(lst));
		}



}
