/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:33:57 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/29 14:15:02 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_onecar(char type, va_list args)
{
	char	*str;

	str = malloc(2);
	str[1] = '\0';
	if (type == 'c')
		str[0] = va_arg(args, int);
	if (type == '%')
		str[0] = '%';
	return (str);
}

char	*ft_argtype(char type, va_list args)
{
	char	*str;

	if (type == 'c' || type == '%')
		str = ft_onecar(type, args);
	if (type == 's')
		str = va_arg(args, char *);
	if (type == 'p')
		str = ft_hextoap(va_arg(args, unsigned long));
	if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(args, int));
	if (type == 'u')
		str = ft_uitoa(va_arg(args,unsigned int));
	if (type == 'x')
		str = ft_hextoa(va_arg(args, unsigned int));
	if (type == 'X')
		str = ft_strupcase(ft_hextoa(va_arg(args, unsigned int)));
	return (str);
}
