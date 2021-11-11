/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/11 15:10:21 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

bool	ft_checktype(const char *input, char *set, int j, const int nbflag)
{
	int 		i;

	i = 0;
	while (set[i] != '\0' && j <= nbflag)
	{
		if (input[j + i] = set[i])
			return (true);
		else
			i++;
	}
	return (false);
}
