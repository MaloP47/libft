/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:28:03 by mpeulet           #+#    #+#             */
/*   Updated: 2024/04/04 17:39:25 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
** SYNOPSIS: memory allocation
**
** DESCRIPTION:
** 		The calloc() function contiguously allocates enough space for count
**	objects that are size bytes of memory each and returns a pointer to the
**	allocated memory. The allocated memory is filled with bytes of value
**	zero.
*/

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	if (nb && size > SIZE_MAX / nb)
        return (NULL);
	ptr = (void *)malloc(nb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb * size);
	return (ptr);
}
