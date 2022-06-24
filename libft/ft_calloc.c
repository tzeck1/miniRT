/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiebert <rsiebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:16:08 by rsiebert          #+#    #+#             */
/*   Updated: 2022/06/24 19:01:56 by rsiebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	if (p == NULL)
	{
		fprintf(stderr, ERROR"%s\n", strerror(errno));
		ft_exit(EXIT_FAILURE);
	}
	return (p);
}
