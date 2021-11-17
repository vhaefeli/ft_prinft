/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:40:20 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/17 13:57:56 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

bool	ft_checktype(char *input, char *set, int start, int nbcheck)
{
	int	i;

	i = 0;
	while (set[i] != '\0' && (start + i) <= nbcheck)
	{
		if (input[start + i] == set[i])
			return (true);
		else
			i++;
	}
	return (false);
}
