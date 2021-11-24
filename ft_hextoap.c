/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/24 15:41:38 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static size_t	hexlen(unsigned long nb)
{
	size_t	ln;

	ln = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 16;
		ln++;
	}
	return (ln);
}

char	*ft_hextoap(unsigned long nb)
{
	char	*hexstr;
	char	*basehex;
	size_t	i;

	basehex = "0123456789abcdef";
	i = hexlen(nb) + 2;
	hexstr = malloc(i + 3);
	if (!hexstr)
		return (NULL);
	hexstr[i] = '\0';
	i--;
	while (i > 1)
	{
		hexstr[i] = basehex[nb % 16];
		nb = nb / 16;
		i--;
	}
	hexstr[0] = '0';
	hexstr[1] = 'x';
	return (hexstr);
}
