/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processflagbefore.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/17 18:17:39 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int	ft_pointleftz(const char *input, int j, int nbflag, char *str)
{
	char	*nb;
	int		pointnb;
	int		i;
	int		k;

	pointnb = 0;
	i = 0;
	k = j;
	if (ft_checktype(input, ".", j, nbflag))
	{
		while (input[k] != ".")
			k++;
		k++;
		while (input[k] < 58)
			nb[i++] = input[k++];
		nb[i] = "\0";
		pointnb = ft_atoi(nb);
	}
	if ((pointnb - ft_strlen(str)) < 0)
		return (0);
	return (pointnb - ft_strlen(str));
}

static int	ft_nbpoint(const char *input, int j, const int nbflag)
{
	char	*nb;
	int		nbpoint;
	int		i;
	int		k;

	nbpoint = 0;
	i = 0;
	k = j;
	if (ft_checktype(input, "123456789", j, nbflag))
	{
		while (input[k] != "." && k <= nbflag)
		{
			if (input[k] > 47 && input[k] < 58)
				nb[i++] = input[k++];
			else
				k++;
		}
		nb[i] = "\0";
		nbpoint = ft_atoi(nb);
	}
	return (nbpoint);
}

static int	ft_spacezero(const char *input, int j, const int nbflag, char *str)
{
	int	spacezero;

	spacezero = ft_nbpoint(input, j, nbflag)
		- ft_pointleftz(input, j, nbflag, str) - ft_strlen(str);
	if (ft_checktype(input, " +", j, nbflag))
		spacezero -= 1;
	else if (ft_checktype(input, "#", j, nbflag))
		spacezero -= 2;
	if (spacezero < 0)
		return (0);
	return (spacezero);
}

static size_t	ft_beforesize(const char *input, int j, int nbflag, char *str)
{
	size_t	beforesize;

	beforesize = ft_pointleftz(input, j, nbflag, str);
	if (str[0] == "-")
		beforesize++;
	else if (ft_checktype(input, " +", j, nbflag))
		beforesize++;
	if (ft_checktype(input, "#", j, nbflag) || input[j + nbflag] == "p")
		beforesize += 2;
	if (!ft_checktype(input, "-", j, nbflag))
		beforesize += ft_spacezero(input, j, nbflag, str);
	return (beforesize);
}	

char	*ft_processflagbefore(const char *input, int j, int nbflag, char *str)
{	
	char	*beforestr;
	int		i;

	i = 0;
	beforestr = malloc(ft_beforesize(input, j, nbflag, str));
	if (!ft_checktype(input, "0-", j, nbflag))
	{
		while (i < ft_spacezero(input, j, nbflag, str))
			beforestr[i++] = " ";
	}
	if (str[0] == "-")
		beforestr[i++] = "-";
	else if (ft_checktype(input, "+" j, nbflag))
		beforestr[i++] = "+";
	else if (ft_checktype(input, " " j, nbflag))
		beforestr[i++] = " ";
	else if (ft_checktype(input, "#" j, nbflag) || input[j + nbflag] == "p")
	{
		beforestr[i++] = "0";
		beforestr[i++] = "x";
	}
	while (i < ft_beforesize(input, j, nbflag, str))
		beforestr[i++] = "0";
	beforestr[i] = "\0";
	return (beforestr);
}
