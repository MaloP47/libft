/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:43:16 by mpeulet           #+#    #+#             */
/*   Updated: 2023/05/24 13:21:41 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: convert ASCII string to double
**
** DESCRIPTION:
** 		The atof() function converts the initial portion of the string pointed
**	to by str to double.
*/

#include "libft.h"

static int	skipspace_sign(const char *s, int *sign)
{
	int	i;

	i = 0;
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i++] == 45)
			*sign *= -1;
	}
	return (i);
}

double	ft_atof(const char *s)
{
	int		i;
	int		sign;
	double	nb;
	double	div;

	sign = 1;
	nb = 0;
	div = 0.1;
	i = skipspace_sign(s, &sign);
	while (s[i] && (s[i] >= 48 && s[i] <= 57) && s[i] != 46)
	{
		nb = (nb * 10) + (s[i] - 48);
		i++;
	}
	if (s[i] == 46)
		i++;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		nb = nb + ((s[i] - 48) * div);
		div *= 0.1;
		i++;
	}
	return (nb * sign);
}
