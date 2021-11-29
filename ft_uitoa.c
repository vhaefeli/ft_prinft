/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:41:17 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/29 14:18:56 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_unitp10(unsigned long nb)
{
	unsigned long	d;

	d = 1;
	if (nb == 0)
		return (1);
	while (nb)
	{
		d *= 10;
		nb /= 10;
	}
	return (d / 10);
}

static size_t	ft_ln(unsigned int n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		l = 1;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

char	*ft_uitoa(unsigned int n)
{
	char			*nbr;

	size_t			i;
	size_t			d;
	size_t			l;

	i = 0;
	l = ft_ln(n);
	d = ft_unitp10(n);
	nbr = malloc(l + 1);
	if (!nbr)
		return (NULL);
	if (n < 0)
		nbr[i++] = '-';
	while (i < l)
	{
		nbr[i++] = '0' + ((n / d) % 10);
		d = d / 10;
	}
	nbr[i] = '\0';
	return (nbr);
}
