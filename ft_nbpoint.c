/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/22 19:02:37 by vhaefeli         ###   ########.fr       */
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
	nb = malloc(nbflag);
	if (ft_checktype(input, "123456789", j, nbflag))
	{
		while (input[k] != '.' && k <= nbflag)
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
//	printf("nbpoint: %i\n", nbpoint);
	return (nbpoint);
}
