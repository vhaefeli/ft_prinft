/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:11:00 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

bool	ft_checktype(const char *input, char *set, const int start, const int nbcheck)
{
	int 		i;

	i = 0;
	while (set[i] != '\0' && (start + i) <= nbcheck)
	{
		if (input[start + i] = set[i])
			return (true);
		else
			i++;
	}
	return (false);
}
