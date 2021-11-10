/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:42:24 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/10 20:37:55 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libftprintf.h"

static bool	checkiftype(char input)
{
	char const *set;
	int 		i;

	i = 0;
	set = "cspdiuxX%";
	while (set[i] != '\0')
	{
		if (input[0] = set[i])
			return (true);
		else
			i++;
	}
	return (false);
}
			
static int	checknbflag(char const *input, i)
{
	int nbflag;

	nbflag = 0;
	while (!checkiftype(input[i + 1]))
			{
				i++ ;
				nbflag++;
			}
	return (nbflag);
}


int	ft_printf(char const *input, ...)
{
	va_list	args;
	int		i;
	int		nbflag;
	int		sizedst;

	sizedst = 0;
	i = 0;
	nbflag = 0;
	va_start(args, input);
	while (i < ft_strlen(input))
		if (input[i] == % && input[i + 1] != '\0')
		{
			nbflag = checknbflag(input, i);
			sizedst += ft_processargprintf(input, args, i + 1, nbflag);
			i = i + nbrflag + 2;
		}
		else
		{
			write(1, input[i], 1);
			i++;
			sizedst++;
		}
	va_end(args);
	return (sizedst);		
}
