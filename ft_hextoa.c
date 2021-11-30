/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/30 16:32:32 by vhaefeli         ###   ########.fr       */
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

char	*ft_hextoa(unsigned long nb)
{
	char	*hexstr;
	char	*basehex;
	size_t	i;

	basehex = "0123456789abcdef";
	i = hexlen(nb);
	hexstr = malloc(i + 1);
	if (!hexstr)
		return (NULL);
	hexstr[i] = '\0';
	i--;
	while (i >= 0)
	{
		hexstr[i] = basehex[nb % 16];
		nb = nb / 16;
		if (i == 0)
			break ;
		i--;
	}
	return (hexstr);
}
