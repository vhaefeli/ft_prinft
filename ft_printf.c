/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:42:24 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:46 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	checkiftype(char input)
{
	char	*set;
	int		i;

	i = 0;
	set = "cspdiuxX%";
	while (set[i] != '\0')
	{
		if (input == set[i])
			return (true);
		else
			i++;
	}
//	printf("checkiftype\n");
	return (false);
}

static int	checknbflag(const char *input, int i)
{
	int	nbflag;

	nbflag = 0;
	while (!checkiftype(input[i + 1]))
	{
		i++ ;
		nbflag++;
	}
//	printf("nbflag: %i\n",nbflag);
	return (nbflag);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		nbflag;
	int		sizedst;

	sizedst = 0;
	i = 0;
	va_start(args, input);
	while (i < (int)ft_strlen(input))
	{
//		printf("\ni = %d, input[i]= %c\n", i, input[i]);
		if (input[i] == '%' && input[i + 1] != '\0')
		{
			nbflag = checknbflag(input, i);
//			printf("nbflag %d input i+1 :%c\n", nbflag, input[i+1]);
			sizedst += ft_argprint(input, args, i + 1, nbflag);
			i = i + nbflag + 2;
//			printf("printf  if\n");
		}
		else
		{
			write(1, &input[i], 1);
			i++;
			sizedst++;
//			printf(" : printinput\n");
		}
	}
	va_end(args);
	return (sizedst);
}
