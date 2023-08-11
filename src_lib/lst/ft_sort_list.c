/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:57:40 by mpeulet           #+#    #+#             */
/*   Updated: 2023/05/24 11:34:36 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* FOR INT ONLY*/

/* Example of sorting function */
/*
int	ascending(int a, int b)
{
	return (a <= b);
}
*/
/* *************************** */

static void	swap_t_int(t_int *a, t_int *b)
{
	int	temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

t_int	*ft_sort_int(t_int *lst, int (*cmp)(int, int))
{
	int		valid;
	t_int	*tmp;

	valid = 1;
	tmp = lst;
	while (valid == 1)
	{
		valid = 0;
		while (tmp && tmp->next)
		{
			if (cmp(tmp->content, tmp->next->content) == 0)
			{
				swap_t_int(tmp, tmp->next);
				valid = 1;
			}
			tmp = tmp->next;
		}
		tmp = lst;
	}
	return (lst);
}
