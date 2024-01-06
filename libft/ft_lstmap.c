/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgebski <kgebski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:41:17 by kgebski           #+#    #+#             */
/*   Updated: 2024/01/06 02:22:22 by kgebski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	del_c_and_n(t_list *result, void (*del)(void *), void *content)
{
	ft_lstclear(&result, del);
	del(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*content;
	t_list	*node;

	result = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		content = f(tmp->content);
		if (!content)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		node = ft_lstnew(content);
		if (!node)
			del_c_and_n(result, del, content);
		ft_lstadd_back(&result, node);
		tmp = tmp->next;
	}
	return (result);
}
