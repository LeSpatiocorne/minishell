/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:06:01 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 14:26:59 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

// 	new_node = ft_lstnew("Third");
// 	ft_lstadd_front(&list, new_node);
// 	print_list(list);

// 	new_node = ft_lstnew("Second");
// 	ft_lstadd_front(&list, new_node);
// 	print_list(list);

// 	new_node = ft_lstnew("First");
// 	ft_lstadd_front(&list, new_node);
// 	print_list(list);

// 	return (0);
// }