/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:54:51 by mpeulet           #+#    #+#             */
/*   Updated: 2022/11/10 16:29:05 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: output integer to given file
**
** DESCRIPTION:
** 		Outputs the integer ’n’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	div;
	long int	mod;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd(45, fd);
		nb *= -1;
	}
	div = nb / 10;
	mod = nb % 10;
	if (div)
		ft_putnbr_fd(div, fd);
	ft_putchar_fd(mod + 48, fd);
}	
