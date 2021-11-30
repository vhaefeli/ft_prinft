/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/30 17:16:36 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbpoint(const char *input, int j, int nbflag)
{
	char	*nb;
	int		nbpoint;
	int		i;
	int		k;

	nbpoint = 0;
	i = 0;
	k = j;
	nb = malloc(nbflag + 1);
	if (ft_checktype(input, "123456789", j, nbflag))
	{
		while (input[k] != '.' && k <= (j + nbflag))
		{
			if (input[k] > 47 && input[k] < 58)
				nb[i++] = input[k++];
			else
				k++;
		}
		nb[i] = '\0';
		nbpoint = ft_atoi(nb);
	}
	free(nb);
	return (nbpoint);
}
