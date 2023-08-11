/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:31:28 by mpeulet           #+#    #+#             */
/*   Updated: 2022/11/26 13:15:08 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: convert integer to ASCII string
**
** DESCRIPTION:
** 		Allocates (with malloc(3)) and returns a string representing the
**	integer received as an argument. Negative numbers must be handled.
*/

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static int	ft_intlen(int nb)
{
	int	res;

	res = 0;
	if (nb <= 0)
	{
		res = 1;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	long int	nb;

	nb = n;
	s = ft_calloc(ft_intlen(nb) + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (nb == 0)
	{
		s[0] = 48;
		return (s);
	}
	if (nb < 0)
	{
		s[ft_intlen(nb) - 1] = 45;
		nb *= -1;
	}
	i = 0;
	while (nb != 0)
	{
		s[i++] = 48 + (nb % 10);
		nb = (nb / 10);
	}
	return (ft_strrev(s));
}
