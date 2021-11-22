/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:32:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/22 17:37:28 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lencutstr(const char *input, int j, int nbflag, char *str)
{
	char	*nb;
	int		pointnb;
	int		i;
	int		k;

	pointnb = 0;
	i = 0;
	k = j;
	nb  = malloc(nbflag);
	if (ft_checktype(input, ".", j, nbflag))
	{
		while (input[k] != '.')
			k++;
		k++;
		while (input[k] < 58)
			nb[i++] = input[k++];
		nb[i] = '\0';
		pointnb = ft_atoi(nb);
	}
	free(nb);
	if ((pointnb - ft_strlen(str)) < 0)
		return (ft_strlen(str));
	return (pointnb);
}

static size_t	ft_nbpoint(const char *input, int j, int nbflag)
{
	char	*nb;
	size_t		nbpoint;
	int		i;
	int		k;

	nbpoint = 0;
	i = 0;
	k = j;
	nb = malloc(nbflag);
	if (ft_checktype(input, "123456789", j, nbflag))
	{
		while (input[k] != '.' && k <= nbflag)
		{
			if (input[k] > 47 && input[k] < 58)
				nb[i++] = input[k++];
			else
				k++;
		}
		nb[i] = '\0';
		nbpoint = ft_atoi(nb);
	}
	free(nb);
	return (nbpoint);
}

size_t	ft_flstring(const char *input, int j, int nbflag, char *str)
{
	size_t	i;
	size_t	k;
	size_t	pointnb;

	i = 0;
	k = 0;
	pointnb = (size_t)ft_lencutstr(input, j, nbflag, str);
	if (ft_checktype(input, "-", j, nbflag))
	{
		while (i < pointnb)
			write (1, &str[i++], 1);
		while (i++ < ft_nbpoint(input, j, nbflag))
			write (1, " ", 1);
	}
	else
	{
		while (i++ < ft_nbpoint(input, j, nbflag) - pointnb)
			write (1, " ", 1);
		while (i++ < ft_nbpoint(input, j, nbflag))
			write (1, &str[k++], 1);
	}
	if (ft_nbpoint(input, j, nbflag) > pointnb)
		return (ft_nbpoint(input, j, nbflag));
	return (pointnb);
}
