/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doller-m <doller-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:02:56 by doller-m          #+#    #+#             */
/*   Updated: 2023/06/22 13:13:39 by doller-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nd_actual;
	t_list	*nd_siguiente;

	if (lst)
	{
		nd_actual = *lst;
		while (nd_actual)
		{
			nd_siguiente = nd_actual->next;
			ft_lstdelone(nd_actual, del);
			nd_actual = nd_siguiente;
		}
		*lst = NULL;
	}
}
