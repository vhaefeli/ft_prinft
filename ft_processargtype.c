/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:33:57 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/17 18:21:24 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static char	*ft_strupcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

static unsigned int	ft_unsigned(int i)
{
	unsigned int	uint;

	if (i < 0)
		uint = (INT_MAX) + i + 1;
	else
		uint = i;
	return (uint);
}

char	*ft_processargtype(char type, va_list args)
{
	char	*str;

	if (type == "c")
		str = va_arg(args, int);
	if (type == "s")
		str = va_arg(args, char);
	if (type == "p")
		str == ft_hextoa(va_arg(args, long long));
	if (type == "d" || type == "i")
		str == ft_itoa(va_arg(args, int));
	if (type == "u")
		str = ft_itoa(ft_unsigned(va_arg(args, int)));
	if (type == "x")
		str == ft_hextoa(va_arg(args, long long));
	if (type == "X")
		str == ft_strupcase(ft_hextoa(va_arg(args, long long)));
	if (type == "%")
		str == "%";
	return (str);
}
