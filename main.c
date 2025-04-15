/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:05:13 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:28:49 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (init_stack(ac, av, &a) == 1)
		return (1);
	if (check_duplicate(a) == 0)
		return (lstclear(a), write(2, "Error\n", 6), 1);
	ft_index_by_data(a);
	check_sort(&a);
	handle_sort(&a, &b);
	lstclear(a);
}
