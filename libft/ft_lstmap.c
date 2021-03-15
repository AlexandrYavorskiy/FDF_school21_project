/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:00:14 by rkaley            #+#    #+#             */
/*   Updated: 2019/10/05 19:16:40 by rkaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*copy;

	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		if (!(new = f(lst)))
			return (NULL);
		copy = new;
		while (lst->next)
		{
			if (!(copy->next = f(lst->next)))
			{
				ft_lstdel(&new, ft_free);
				return (NULL);
			}
			copy = copy->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
