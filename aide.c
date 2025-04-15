/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:02:17 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:21:31 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_list *list)
{
	t_list	*current;

	while (list)
	{
		current = (list)->next;
		free(list);
		list = current;
	}
	list = NULL;
}

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_duplicate(t_list	*list)
{
	t_list	*reccur;

	while (list)
	{
		reccur = list->next;
		while (reccur)
		{
			if (reccur->data == list->data)
				return (0);
			reccur = reccur->next;
		}
		list = list->next;
	}
	return (1);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

int	check_num(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i != len)
		return (0);
	return (1);
}
