/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_stdout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:17:24 by mpeulet           #+#    #+#             */
/*   Updated: 2023/07/13 10:30:38 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
** SYNOPSIS: output string to stdout with newline
**
** DESCRIPTION:
** 		Outputs the string ’s’ to stdout, followed by a newline.
*/

#include "libft.h"

void	ft_putendl_stdout(char *s)
{
	if (!s)
		return ;
	ft_putstr_stdout(s);
	ft_putchar_stdout(10);
}
