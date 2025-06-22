/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:14:15 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 16:40:53 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// void print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s -> ", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*new_node;

// 	print_list(list);

// 	new_node = ft_lstnew("First");
// 	ft_lstadd_back(&list, new_node);
// 	print_list(list);

// 	new_node = ft_lstnew("Second");
// 	ft_lstadd_back(&list, new_node);
// 	print_list(list);

// 	new_node = ft_lstnew("Third");
// 	ft_lstadd_back(&list, new_node);
// 	print_list(list);

// 	return (0);
// }