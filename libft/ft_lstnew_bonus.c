/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:11:19 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 14:03:50 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	char	*content = "Cargaison for my wagon";
// 	t_list	*new_node = ft_lstnew(content);

// 	if (new_node)
// 	{
// 		printf("content: %s\n", (char *)new_node->content);
// 		printf("next: %p\n", (void *)new_node->next);
// 		free(new_node);
// 	}
// 	else
// 		printf("fail :(\n");
// 	return (0);
// }

/*so, the lsit is like a big train, with multiple wagons
each wagon has some content
I want to add a new wagon
So I need to create the wagon, then put its content inside it
But to create a new wagon, I need its dimensions
	=> malloc t_list
If it worked correctly, I can then be a train director
I say "In the wagon, put the content"
	=> "[wagon] -> content = content"
after that, I need to say that there is nothing after i/it's not connected yet
	=> "[wagon] -> next = NULL"
after all is good, I give back my wagon, full and not connected for now*/