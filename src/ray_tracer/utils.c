/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42HN.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:38 by rsiebert          #+#    #+#             */
/*   Updated: 2022/08/02 16:28:39 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

/**
 * @brief  returns the smallest int
 */
int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
