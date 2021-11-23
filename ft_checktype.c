/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:40:20 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/23 17:35:12 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_checktype(const char *input, char *set, int start, int nbcheck)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (j <= nbcheck)
	{
		while (set[i] != '\0')
		{
			if (input[start + j] == set[i])
			{
				return (true);
			}
			else
				i++;
		}
		j++;
		i = 0;
	}
	return (false);
}
