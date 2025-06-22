/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:57:34 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/21 09:36:25 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// void	delete(void *content)
// {
// 	free(content);
// }

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

// 	ft_lstdelone(list, &delete);
// 	print_list(list);

// 	return (0);
// }