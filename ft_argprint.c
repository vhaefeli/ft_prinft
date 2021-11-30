/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/30 17:27:56 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putustr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ((void) NULL);
	if (s[0] == '-')
		i++;
	while (i < ft_strlen(s))
		write (1, &s[i++], 1);
}

static size_t	ft_printarg(const char *input, char *str, int j, int nbflag)
{
	size_t	addsize;
	size_t	i;
	char	*beforestr;

	if (!str)
		str = "(null)";
	i = j + nbflag;
	addsize = ft_strlen(str);
	if (str[0] == '0' && str[1] == '\0' && ft_checktype(input, ".", j, nbflag))
	{
		str[0] = '\0';
		addsize = 0;
	}
	beforestr = ft_flbefore(input, j, nbflag, str);
	ft_putstr_fd(beforestr, 1);
	ft_putustr(str);
	if (str[0] == '-')
		addsize--;
	addsize += ft_strlen(beforestr);
	addsize += ft_flafter(input, j, nbflag, str);
	free(beforestr);
	free(str);
	return (addsize);
}

static size_t	ft_printc(const char *input, va_list args, int j, int nbflag)
{
	size_t	addsize;
	char	*beforestr;
	char	*str;

	addsize = 1;
	str = malloc(3);
	str [0] = '1';
	str [1] = '\0';
	beforestr = ft_flbefore(input, j, nbflag, str);
	ft_putstr_fd(beforestr, 1);
	ft_putchar_fd(va_arg(args, int), 1);
	addsize += ft_strlen(beforestr);
	addsize += ft_flafter(input, j, nbflag, str);
	free(beforestr);
	free(str);
	return (addsize);
}

static size_t	ft_printstr(const char *input, char *str, int j, int nbflag)
{
	size_t	addsize;

	if (!str)
		str = "(null)";
	if (ft_checktype(input, ".-0123456789", j, nbflag))
		addsize = ft_flstring(input, j, nbflag, str);
	else
	{
		ft_putstr_fd(str, 1);
		addsize = ft_strlen(str);
	}
	return (addsize);
}

size_t	ft_argprint(const char *input, va_list args, int j, int nbflag)
{
	size_t	addsize;
	size_t	i;
	char	*str;

	i = j + nbflag;
	if (input[i] == 'c')
		addsize = ft_printc(input, args, j, nbflag);
	else
	{
		str = ft_argtype(input[i], args);
		if (input[i] == 's')
			addsize = ft_printstr(input, str, j, nbflag);
		else
			addsize = ft_printarg(input, str, j, nbflag);
	}
	return (addsize);
}
