/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/10 17:54:40 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static
static bool	checkiftype(char input)
{
	char const *set;
	int 		i;

	i = 0;
	set = " -+";
	while (set[i] != '\0')
	{
		if (input[0] = set[i])
			return (true);
		else
			i++;
	}
	return (false);
}

int ft_processargprintf(char const *input, va_list args, int j, int const nbflag)
{
	int 	addsize;
	int		i;
	char	*str;

	i = j + nbflag;
	

	


	return (addsize);
}
