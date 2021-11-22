/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:40:20 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/20 16:38:47 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_checktype(const char *input, char *set, int start, int nbcheck)
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
