/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processargprintf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:38:09 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:11:24 by vhaefeli         ###   ########.fr       */
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

int ft_processargprintf(const char *input, va_list args, int j, const int nbflag)
{
	size_t	addsize;
	int		i;
	char	*str;
	char	*beforestr;

	i = j + nbflag;
	str = ft_processargtype(input[i], args);
	addsize = ft_strlen(str);
	beforestr = ft_processflagbefore(input, j, nbflag, str);
	ft_putstr_fd(beforestr, 1);
	ft_putustr_fd(str, 1);
	addsize += ft_strlen(beforestr) + ft_strlen(afterstr);
	addsize += ft_processflagafter(input, j, nbflag, addsize);
	free(str);
	free(beforestr);
	return (addsize);
}
