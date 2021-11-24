/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flbefore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/24 16:16:31 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_checkzero(const char *input, int j, int nbflag)
{
	int	i;

	i = 0;
	while (i <= nbflag)
	{
		if (input[j + i] > 48)
			return (false);
		if (input[j + i] == 48)
			return (true);
		i++;
	}
	return (false);
}
