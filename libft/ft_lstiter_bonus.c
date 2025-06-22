/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:52:21 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/21 10:35:33 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*node;

	node = lst;
	while (node)
	{
		(*f)(node->content);
		node = node->next;
	}
}

// void	scream_function(void *elem)
// {
// 	int		len;
// 	char	*content;

// 	len = 0;
// 	content = (char *)elem;

// 	while (content[len])
// 		content[len++] = 'A';
// }

// void	print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		printf("%s -> ", (char *)list->content);
// 		list = list->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	char	*str1 = ft_strdup("First");
// 	char	*str2 = ft_strdup("Second");
// 	char	*str3 = ft_strdup("Third");

// 	t_list	*elem1 = ft_lstnew(str1);
// 	t_list	*elem2 = ft_lstnew(str2);
// 	t_list	*elem3 = ft_lstnew(str3);

// 	elem1->next = elem2;
// 	elem2->next = elem3;
// 	printf("Original list:\n");
// 	print_list(elem1);

// 	ft_lstiter(elem1, &scream_function);
// 	printf("New list with the scream function:\n");
// 	print_list(elem1);
// 	return (0);
// }