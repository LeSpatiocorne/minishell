/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:32:35 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:03 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*new_node;

// 	new_node = ft_lstnew("Third");
// 	ft_lstadd_front(&list, new_node);

// 	new_node = ft_lstnew("Second");
// 	ft_lstadd_front(&list, new_node);

// 	new_node = ft_lstnew("First");
// 	ft_lstadd_front(&list, new_node);

// 	int	how_many = ft_lstsize(list);
// 	printf("%d\n", how_many);

// 	return (0);
// }