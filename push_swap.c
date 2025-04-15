/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:21:13 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/11 09:42:26 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rangestr(t_list *stack_a)
{
	int	len;
	int	range;

	range = 0;
	len = ft_size_liste(stack_a);
	if (len <= 100)
		range = 16;
	else
		range = 36;
	return (range);
}

int	check_test(t_list **stack_a)
{
	int		len;
	int		count;
	t_list	*tmp;

	len = ft_size_liste(*stack_a) / 2;
	count = 0;
	tmp = *stack_a;
	while (len > 0)
	{
		if (tmp->index > tmp->next->index)
			count++;
		else
			count--;
		tmp = tmp->next;
		len--;
	}
	if (count < ft_size_liste(*stack_a) / 2)
		return (1);
	else
		return (0);
}

void	aller_algo(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	range;
	int	check;

	check = check_test(stack_a);
	i = 0;
	range = rangestr(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pa(stack_a, stack_b, 0);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pa(stack_a, stack_b, 0);
			ra(stack_b, 'b');
			i++;
		}
		else if (check != 1)
			rra(stack_a, 'a');
		else
			ra(stack_a, 'a');
	}
}

void	retour_algo(t_list **stack_b, t_list **stack_a)
{
	int		max;
	t_list	*next;
	int		i;
	int		len;

	i = 0;
	while (*stack_b)
	{
		max = ft_pose_max(*stack_b);
		len = ft_size_liste(*stack_b);
		next = *stack_b;
		i = 0;
		while (next)
		{
			if (next->data == max)
				break ;
			i++;
			next = next->next;
		}
		aide_retour(stack_b, stack_a, &len, &i);
	}
}

void	aide_retour(t_list **stack_b, t_list **stack_a, int *len, int *i)
{
	if (*i <= (*len / 2))
	{
		while (*i > 0)
		{
			ra(stack_b, 'b');
			(*i)--;
		}
	}
	else
	{
		while (*i < *len)
		{
			rra(stack_b, 'b');
			(*i)++;
		}
	}
	pa(stack_b, stack_a, 1);
}
