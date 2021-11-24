/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flbefore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/24 13:48:06 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_plusspace(const char *input, int j, int nbflag)
{
	char	plusspace;

	if (ft_checktype(input, "+", j, nbflag))
		plusspace = '+';
	else
		plusspace = ' ';
	return (plusspace);
}
