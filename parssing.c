/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:09:30 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:29:27 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int ac, char **av, t_list **a)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str)
			return (lstclear(*a), 1);
		j = 0;
		if (!str[j])
		{
			lstclear(*a);
			freestr(str);
			write(2, "Error\n", 6);
			return (1);
		}
		if (ft_healpstack(str, &j, a) == 1)
			return (1);
		freestr(str);
		i++;
	}
	return (0);
}

int	ft_healpstack(char **str, int *j, t_list **a)
{
	int	num;

	num = 0;
	while (str[*j])
	{
		if (check_num(str[*j]) == 0)
		{
			freestr(str);
			lstclear(*a);
			write(2, "Error\n", 6);
			return (1);
		}
		num = ft_atoi(str[*j], *a, str);
		lstadd_back(a, ft_lstnew(num));
		(*j)++;
	}
	return (0);
}

void	handle_sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_size_liste(*a);
	if (len == 2)
		ft_srt2(a);
	if (len == 3)
		ft_srt3(a);
	else if (len == 4)
		ft_srt4(a, b);
	else if (len == 5)
		ft_srt5(a, b, 0);
	else if (len > 5)
	{
		aller_algo(a, b);
		retour_algo(b, a);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

void	check_sort(t_list **a)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *a;
	while (current)
	{
		if ((current)->index != i)
			return ;
		current = (current)->next;
		i++;
	}
	lstclear(*a);
	exit (1);
}
