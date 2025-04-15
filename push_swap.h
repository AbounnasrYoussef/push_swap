/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:06:16 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 17:53:37 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

char	**ft_split(char const *s, char c);
int		countwords(const char *str, char c);
int		init_stack(int ac, char **av, t_list **a);
int		ft_healpstack(char **str, int *j, t_list **a);
void	handle_sort(t_list **a, t_list **b);
void	check_sort(t_list **a);
void	ft_srt3(t_list **recurent);
void	ft_srt4(t_list **recurent, t_list **b);
void	ft_tosrt5(t_list **recurent, t_list **b);
void	ft_srt5(t_list **recurent, t_list **b, int i);
void	ft_index_by_data(t_list *list);
int		ft_size_liste(t_list *list);
void	ft_lst_add_front(t_list **lst, t_list *new);
void	sa(t_list *list);
void	rra(t_list **list, char c);
void	ra(t_list **list, char c);
void	pa(t_list **a, t_list **b, int flag);
int		min_value(t_list *recurent);
void	lstclear(t_list *list);
void	freestr(char **str);
int		check_duplicate(t_list	*list);
void	lstadd_back(t_list **lst, t_list *new);
int		check_num(char *str);
int		ft_atoi(const char *str, t_list *stack_a, char **splt);
int		ft_pose_max(t_list *recurent);
void	ft_srt2(t_list **recurent);
void	ft_tosrt4(t_list **recurent, t_list **b);
int		rangestr(t_list *stack_a);
void	aller_algo(t_list **stack_a, t_list **stack_b);
void	retour_algo(t_list **stack_b, t_list **stack_a);
void	aide_retour(t_list **stack_b, t_list **stack_a, int *len, int *i);
int		check_test(t_list **stack_a);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int num);

#endif
