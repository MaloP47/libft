/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:04:03 by mpeulet           #+#    #+#             */
/*   Updated: 2023/08/10 15:03:24 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: Checks if any of char are 0 - 9.
**
** DESCRIPTION:
** 		Runs through the s string and return 0 if a char is >= 48 ascii or <= 57.
**  It's used to check argv mostly.
*/

#include "libft.h"

int	ft_str_isdigit(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == 0)
		return (0);
	if (ft_is_sign(s[0]) && s[1] != 0)
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
