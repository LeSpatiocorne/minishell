/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:52:08 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 15:12:55 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*newwag;

// 	newwag = ft_lstnew("First");
// 	ft_lstadd_front(&list, newwag);
// 	newwag = ft_lstnew("Second");
// 	ft_lstadd_front(&list, newwag);
// 	newwag = ft_lstnew("Third");
// 	ft_lstadd_front(&list, newwag);
// 	newwag = ft_lstnew("Third");
// 	ft_lstadd_front(&list, newwag);
// 	newwag = ft_lstnew("Third");
// 	ft_lstadd_front(&list, newwag);

// 	t_list	*res = ft_lstlast(list);
// 	printf("Last wagon to FunLand: %s\n", (char *)res->content);
// 	return (0);
// }