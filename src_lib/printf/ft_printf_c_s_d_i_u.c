/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s_d_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:40:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/04/26 12:14:25 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: Utils for ft_printf.
** 
** DESCRIPTION:
** 		These functions manage %c, %s, %d, %i, and %u flags.
*/

#include "libft.h"

/* Managing %c flag */

void	ft_printf_char(t_pff *tab)
{
	char	a;

	a = va_arg(tab->args1, int);
	tab->tl += write(1, &a, 1);
}

/* Managing %s flag */

int	ft_put_str_printf(t_pff *tab)
{
	char	*s;

	s = va_arg(tab->args1, char *);
	if (s == 0)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

/* Managing %d & %i flags using itoa */

void	ft_put_idnbr_printf(t_pff *tab)
{
	char	*s;

	s = ft_itoa(va_arg(tab->args1, int));
	tab->tl += write(1, s, ft_strlen(s));
	free(s);
}

/* Managing %u flag using recursive to write each digit */

/****************************************************************/

void	print_unbr(unsigned int ui, t_pff *tab)
{
	if (ui == 0 || (ui > 0 && ui <= 9))
		tab->tl += ft_putcharpf(ui + 48);
	else if (ui >= 10)
	{
		print_unbr(ui / 10, tab);
		print_unbr(ui % 10, tab);
	}
}

void	ft_put_unbr_printf(t_pff *tab)
{
	unsigned int	ui;

	ui = va_arg(tab->args1, unsigned int);
	print_unbr(ui, tab);
}

/****************************************************************/
