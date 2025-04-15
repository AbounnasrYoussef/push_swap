/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aide_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:14:13 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:22:00 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_by_data(t_list *list)
{
	t_list	*current;
	t_list	*next;
	int		temp_index;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		next = list;
		temp_index = 0;
		while (next)
		{
			if (next->data < current->data)
				temp_index++;
			next = next->next;
		}
		current->index = temp_index;
		current = current->next;
	}
}

int	ft_size_liste(t_list *list)
{
	t_list	*help;

	help = list;
	if (!list)
		return (0);
	return (1 + ft_size_liste(help->next));
}

t_list	*ft_lstnew(int num)
{
	t_list	*list;

	list = malloc (sizeof(t_list));
	if (!list)
		return (NULL);
	list->data = num;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lst_add_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst) = new;
}
