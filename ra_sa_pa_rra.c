/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_sa_pa_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:37:18 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:21:04 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *list)
{
	t_list	*head;
	int		tcp;

	head = list;
	tcp = head->data;
	if (!list)
		return ;
	head->data = list->next->data;
	list->next->data = tcp;
	write(1, "sa\n", 3);
}

void	rra(t_list **list, char c)
{
	t_list	*head;
	t_list	*last;

	head = *list;
	last = ft_lstlast(*list);
	if (!list)
		return ;
	while (head)
	{
		if (head->next->next == NULL)
			break ;
		head = head->next;
	}
	head->next = NULL;
	ft_lst_add_front(list, last);
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	ra(t_list **list, char c)
{
	t_list	*head;
	t_list	*front;

	head = (*list)->next;
	front = *list;
	if (!list)
		return ;
	if (!list || !*list || ft_size_liste(*list) < 2)
		return ;
	front->next = NULL;
	*list = head;
	lstadd_back(list, front);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	pa(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = NULL;
	ft_lst_add_front(b, tmp);
	if (flag)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

int	min_value(t_list *recurent)
{
	int		min;
	t_list	*list;

	min = recurent->data;
	list = recurent;
	while (list)
	{
		if (list->data < min)
			min = list->data;
		else
			list = list->next;
	}
	return (min);
}
