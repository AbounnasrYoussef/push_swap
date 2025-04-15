/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:07:32 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:21:24 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_list *stack_a, char **splt)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((sign == 1 && (result > 2147483647))
		|| (sign == -1 && result > 2147483648))
		(freestr(splt), lstclear (stack_a), \
		write(2, "Error\n", 6), exit(1));
	return (result * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_pose_max(t_list *recurent)
{
	int		max;
	t_list	*list;

	max = recurent->data;
	list = recurent;
	while (list)
	{
		if (list->data > max)
			max = list->data;
		list = list->next;
	}
	return (max);
}

void	ft_srt2(t_list **recurent)
{
	int	f;
	int	s;

	f = (*recurent)->data;
	s = (*recurent)->next->data;
	if ((f > s))
		sa(*recurent);
}

void	ft_tosrt4(t_list **recurent, t_list **b)
{
	pa(recurent, b, 0);
	ft_srt3(recurent);
	pa(b, recurent, 1);
}
