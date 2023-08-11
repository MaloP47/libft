/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:40:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/04/26 12:13:38 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdio.h>
** SYNOPSIS: The functions produce output acccording  to a format.
** 
** DESCRIPTION:
** 		The ft_printf functions imitates its famous cousin only 
** managing the following flags : %c %s %d %i %u %p x% X%. It
** returns int of n characters printed.
*/

#include "libft.h"

/* initialize flags management struct with 0 */

t_pff	*init_tab(t_pff *tab)
{
	tab->tl = 0;
	return (tab);
}

/* when '%' is found, the next char formats the ouput */

int	ft_whatisnext(t_pff *tab, const char *s, int i)
{
	if (s[i] == 'c')
		ft_printf_char(tab);
	else if (s[i] == 's')
		tab->tl += ft_put_str_printf(tab);
	else if (s[i] == 'p')
		ft_put_ptr_printf(tab);
	else if (s[i] == 'd' || s[i] == 'i')
		ft_put_idnbr_printf(tab);
	else if (s[i] == 'u')
		ft_put_unbr_printf(tab);
	else if (s[i] == 'x' || s[i] == 'X')
		ft_put_hex_printf(tab, s[i]);
	else if (s[i] == '%')
		tab->tl += write(1, "%", 1);
	return (i);
}

/* main function */

int	ft_printf(const char *format, ...)
{
	int			i;
	int			n_printed;
	t_pff		*tab;

	tab = (t_pff *)malloc(sizeof(t_pff));
	if (!tab)
		return (-1);
	init_tab(tab);
	va_start(tab->args1, format);
	i = -1;
	n_printed = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_whatisnext(tab, format, i + 1);
		else
			n_printed += write(1, &format[i], 1);
	}
	va_end(tab->args1);
	n_printed += tab->tl;
	free(tab);
	return (n_printed);
}
