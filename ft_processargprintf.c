/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/11 15:10:19 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static char *ft_processflagbefore(char const *input, int j, int const nbflag, int addsize)
{
	char	*beforestr;

	if (!ft_checktype(input, " " 

	return (beforestr);
}

static char *ft_processflagafter(char const *input, int j, int const nbflag, int addsize);
{
	char 	*afterstr;

	return (afterstr);
}

int ft_processargprintf(char const *input, va_list args, int j, int const nbflag)
{
	int 	addsize;
	int		i;
	char	*str;
	char	*beforestr;
	char	*afterstr;

	i = j + nbflag;
	if (ft_checktype(input, ".", j, nbflag))
	{
		addsize = ft_precision(input, args, j, nbflag);
		return (addsize);
	}
	str = ft_processargtype(input[i], args);
	addsize = ft_strlen(str);
	beforestr = ft_processflagbefore(input, j, nbflag, addsize);
	afterstr = ft_processflagafter(input, j, nbflag, addsize);
	ft_putstr_fd(beforestr, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(afterstr, 1);
	addsize += ft_strlen(beforestr) + ft_strlen(afterstr);
	free(str);
	free(beforestr);
	free(afterstr);
	return (addsize);
}
