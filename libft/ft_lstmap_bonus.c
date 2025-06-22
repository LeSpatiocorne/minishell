/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:37:44 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/21 13:08:23 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	*scream_function(void *elem)
// {
// 	int		len;
// 	char	*content;

// 	len = 0;
// 	content = (char *)elem;

// 	while (content[len])
// 		content[len++] = 'A';
// 	return (content);
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

// void	delete(void *content)
// {
// 	free(content);
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

// 	ft_lstmap(elem1, &scream_function, &delete);
// 	printf("New list with the scream function:\n");
// 	print_list(elem1);
// 	return (0);
// }