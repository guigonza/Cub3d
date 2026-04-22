/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:44:14 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/08 11:44:15 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_lst;
	t_list	*new_node;
	void	*new_content;

	mapped_lst = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			new_content = f(lst->content);
			new_node = ft_lstnew(new_content);
			if (!new_node)
			{
				del(new_content);
				ft_lstclear(&mapped_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&mapped_lst, new_node);
			lst = lst->next;
		}
	}
	return (mapped_lst);
}
