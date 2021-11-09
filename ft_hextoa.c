/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/09 11:57:58 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t hexlen(long nb)
{
	size_t ln;

	ln = 0;
	while (nb)
	{
		nb = nb / 16;
		ln++;
	}
	return (ln);
}

char	*ft_hextoa(long nb)
{
	char	*hexstr;
	char	*basehex;
	size_t	i;
	
	basehex ="0123456789abcdef";
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
			break;
		i--;
	}
	return (hexstr);
}
