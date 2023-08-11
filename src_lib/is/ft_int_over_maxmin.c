/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_over_maxmin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:16:04 by mpeulet           #+#    #+#             */
/*   Updated: 2023/07/28 08:46:08 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isundermin(long nb)
{
	return (nb < INT_MIN);
}

int	ft_isovermax(long nb)
{
	return (nb > INT_MAX);
}

int	ft_int_over_maxmin(long nb)
{
	return (ft_isundermin(nb) || ft_isovermax(nb));
}
