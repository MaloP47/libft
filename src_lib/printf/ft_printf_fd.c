/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:25:47 by mpeulet           #+#    #+#             */
/*   Updated: 2023/10/20 14:44:29 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putchar_pf(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	putstr_pf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		putchar_pf(s[i++], fd);
	return (i);
}

int	putnbr_pf(int nb, int *count, int fd)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		*count = 1;
		putchar_pf('-', fd);
	}
	if (n > 9)
		putnbr_pf((n / 10), count, fd);
	putchar_pf((n % 10) + '0', fd);
	return (*count += 1);
}

int	print_conversion(va_list *args, const char *s, int i, int fd)
{
	int	count;

	count = 0;
	if (s[i] == 's')
		count = putstr_pf((char *)va_arg(*args, char *), fd);
	else if (s[i] == 'd')
		count = putnbr_pf((int)va_arg(*args, int), &count, fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	int				i;
	int				total;
	va_list			args;

	i = -1;
	total = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			total += print_conversion(&args, s, i, fd);
			continue ;
		}
		else
			total += putchar_pf(s[i], fd);
	}
	va_end(args);
	return (total);
}
