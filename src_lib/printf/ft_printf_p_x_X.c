/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_x_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:40:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/04/26 12:16:30 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: Utils for ft_printf.
** 
** DESCRIPTION:
** 		These functions manage %p, %x and %X flags.
*/

#include "libft.h"

/* Just a regular putchar returning an int */

int	ft_putcharpf(char c)
{
	return (write(1, &c, 1));
}

/* Managing %p flag converting to base 16 + 0x0 */

/****************************************************************/

void	print_ptr(unsigned long p, t_pff *tab)
{
	if (p >= 16)
	{
		print_ptr(p / 16, tab);
		print_ptr(p % 16, tab);
	}
	else
	{
		if (p <= 9)
			tab->tl += ft_putcharpf(p + 48);
		else
			tab->tl += ft_putcharpf(p - 10 + 97);
	}
}

int	ft_put_ptr_printf(t_pff *tab)
{
	unsigned long	p;

	p = va_arg(tab->args1, unsigned long);
	if (p == 0)
		return (tab->tl += write(1, "(nil)", 5));
	tab->tl += write(1, "0x", 2);
	print_ptr(p, tab);
	return (tab->tl);
}

/****************************************************************/

/* Managing %x & %X flags converting to base 16 */

/****************************************************************/

void	print_hex(unsigned int h, t_pff *tab, char c)
{
	if (h >= 16)
	{
		print_hex(h / 16, tab, c);
		print_hex(h % 16, tab, c);
	}
	else
	{
		if (h <= 9)
			tab->tl += ft_putcharpf(h + 48);
		else
		{
			if (c == 'x')
				tab->tl += ft_putcharpf(h - 10 + 97);
			if (c == 'X')
				tab->tl += ft_putcharpf(h - 10 + 65);
		}
	}
}

int	ft_put_hex_printf(t_pff *tab, char c)
{
	unsigned int	h;

	h = va_arg(tab->args1, unsigned int);
	if (h == 0)
		return (tab->tl += write(1, "0", 1));
	print_hex(h, tab, c);
	return (tab->tl);
}

/****************************************************************/