/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:59:05 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/10 14:28:16 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countwords(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static int	ft_count(char const *s, char c, int *end_index, int *strat_index)
{
	int	count_ltr;

	count_ltr = 0;
	while (s[*end_index] == c)
	{
		(*end_index)++;
	}
	*strat_index = *end_index;
	while (s[*end_index] && s[*end_index] != c)
	{
		count_ltr++;
		(*end_index)++;
	}
	return (count_ltr);
}

static void	*free_all(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		array_index;
	int		end_index;
	int		strat_index;
	int		count_ltr;

	array_index = 0;
	end_index = 0;
	strat_index = 0;
	if (!s)
		return (NULL);
	strs = (char **) malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!strs)
		return (NULL);
	while (array_index < countwords(s, c))
	{
		count_ltr = ft_count(s, c, &end_index, &strat_index);
		strs[array_index] = (char *)malloc(sizeof(char) * (count_ltr + 1));
		if (!strs[array_index])
			return (free_all(strs, array_index));
		ft_strlcpy(strs[array_index], s + strat_index, count_ltr + 1);
		array_index++;
	}
	strs[array_index] = NULL;
	return (strs);
}
