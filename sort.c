/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:03:04 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:29:45 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_srt3(t_list **recurent)
{
	int	f1;
	int	s1;
	int	t1;

	f1 = (*recurent)->data;
	s1 = (*recurent)->next->data;
	t1 = (*recurent)->next->next->data;
	if ((f1 > s1) && (f1 > t1) && (s1 < t1))
		ra(recurent, 'a');
	else if ((f1 > s1) && (f1 > t1))
	{	
		sa(*recurent);
		rra(recurent, 'a');
	}
	else if ((f1 > s1) && (f1 < t1))
		sa(*recurent);
	else if ((f1 < s1) && (f1 > t1))
		rra(recurent, 'a');
	else if ((f1 < s1) && (f1 < t1) && (s1 > t1))
	{
		rra(recurent, 'a');
		sa(*recurent);
	}
}

void	ft_srt4(t_list **recurent, t_list **b)
{
	t_list	*list;
	int		min;
	int		i;

	min = min_value(*recurent);
	i = 0;
	list = *recurent;
	while (min != list->data)
	{
		i++;
		list = list->next;
	}
	if (i == 0)
		ft_tosrt4(recurent, b);
	else if (i >= 1)
	{
		while (i <= 3)
		{
			rra(recurent, 'a');
			i++;
		}
		ft_tosrt4(recurent, b);
	}
}

void	ft_tosrt5(t_list **recurent, t_list **b)
{
	pa(recurent, b, 0);
	ft_srt4(recurent, b);
	pa(b, recurent, 1);
}

void	ft_srt5(t_list **recurent, t_list **b, int i)
{
	t_list	*list;
	int		min;

	min = min_value(*recurent);
	list = *recurent;
	while (min != list->data)
	{
		i++;
		list = list->next;
	}
	if (i <= 1)
	{
		if (i != 0)
			ra(recurent, 'a');
		ft_tosrt5(recurent, b);
	}
	else if (i >= 2)
	{
		while (i <= 4)
		{
			rra(recurent, 'a');
			i++;
		}
		ft_tosrt5(recurent, b);
	}
}
