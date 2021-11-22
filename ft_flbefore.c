/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flbefore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/22 11:56:55 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_pointleftz(const char *input, int j, int nbflag, char *str)
{
	char	*nb;
	size_t	pointnb;
	int		i;
	int		k;

	pointnb = 0;
	i = 0;
	k = j;
	nb = malloc(nbflag);
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
//	printf("pointleftz: %lu\n",(pointnb - ft_strlen(str)));
	if (pointnb < ft_strlen(str))
		return (0);
	return (pointnb - ft_strlen(str));
}

static size_t	ft_nbpoint(const char *input, int j, int nbflag)
{
	char	*nb;
	int		nbpoint;
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
//	printf("nbpoint: %i\n", nbpoint);
	return (nbpoint);
}

static size_t	ft_spacezero(const char *input, int j, int nbflag, char *str)
{
	int	spacezero;

	spacezero = ft_nbpoint(input, j, nbflag)
		- ft_pointleftz(input, j, nbflag, str) - ft_strlen(str);
	if (ft_checktype(input, " +", j, nbflag))
		spacezero -= 1;
	else if (ft_checktype(input, "#", j, nbflag))
		spacezero -= 2;
//	printf("spacezero:%i\n", spacezero);
	if (spacezero < 0)
		return (0);
	return ((size_t)spacezero);
}

static size_t	ft_beforesize(const char *input, int j, int nbflag, char *str)
{
	size_t	beforesize;

	beforesize = ft_pointleftz(input, j, nbflag, str);
	if (str[0] == '-')
		beforesize++;
	else if (ft_checktype(input, " +", j, nbflag))
		beforesize++;
	if (ft_checktype(input, "#", j, nbflag) || input[j + nbflag] == 'p')
		beforesize += 2;
	if (!ft_checktype(input, "-", j, nbflag))
		beforesize += ft_spacezero(input, j, nbflag, str);
//	printf("beforesize: %lu\n",beforesize);
	return (beforesize);
}	

char	*ft_flbefore(const char *input, int j, int nbflag, char *str)
{	
	char	*beforestr;
	size_t	i;

	i = 0;
	beforestr = malloc((ft_beforesize(input, j, nbflag, str)) + 2);
	if (!ft_checktype(input, "0-", j, nbflag))
	{
		while (i < ft_spacezero(input, j, nbflag, str))
			beforestr[i++] = ' ';
	}
	if (str[0] == '-')
		beforestr[i++] = '-';
	else if (ft_checktype(input, "+", j, nbflag))
		beforestr[i++] = '+';
	else if (ft_checktype(input, " ", j, nbflag))
		beforestr[i++] = ' ';
	else if (ft_checktype(input, "#", j, nbflag) || input[j + nbflag] == 'p')
	{
		beforestr[i++] = '0';
		beforestr[i++] = 'x';
	}
	while (i < ft_beforesize(input, j, nbflag, str))
		beforestr[i++] = '0';
	beforestr[i] = '\0';
//	printf("beforestr:%s\n",beforestr);
	return (beforestr);
}
