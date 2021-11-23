/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flbefore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:00:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/23 17:28:55 by vhaefeli         ###   ########.fr       */
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
	if (pointnb < ft_strlen(str))
		return (0);
	if (str[0] == '-')
		return (pointnb - ft_strlen(str) + 1);
	return (pointnb - ft_strlen(str));
}

static size_t	ft_spacezero(const char *input, int j, int nbflag, char *str)
{
	long int	spacezero;
//	printf("pointleftz:%li\n", ft_pointleftz(input, j, nbflag, str));
	spacezero = ft_nbpoint(input, j, nbflag)
		- ft_pointleftz(input, j, nbflag, str) - ft_strlen(str);
//	printf("spacezero1:%li\n", spacezero);

	if (ft_checktype(input, " +", j, nbflag))
		spacezero -= 1;
	else if (ft_checktype(input, "#", j, nbflag))
	{
//		printf("#spacezero\n");
		spacezero -= 2;
	}
//	printf("spacezero2:%li\n", spacezero);
	if (spacezero < 0)
		return (0);
	return ((size_t)spacezero);
}

static size_t	ft_beforesize(const char *input, int j, int nbflag, char *str)
{
	size_t	beforesize;

	beforesize = ft_pointleftz(input, j, nbflag, str);
//	printf("beforsize1 :%li\n", beforesize);

	if (str[0] == '-')
		beforesize++;
	else if (ft_checktype(input, " +", j, nbflag))
		beforesize++;
	if ((ft_checktype(input, "#", j, nbflag) && str[0] != '0')
			|| input[j + nbflag] == 'p')
	{
//		printf("#beforesize\n");
		beforesize += 2;
	}
	if (!ft_checktype(input, "-", j, nbflag))
		beforesize += ft_spacezero(input, j, nbflag, str);
//	printf("beforesize: %lu\n",beforesize);
	return (beforesize);
}

static char	ft_xhash(const char *input, int j, int nbflag)
{
	char	xhash;
	
	if (input[j + nbflag] == 'X')
		xhash = 'X';
	else
		xhash = 'x';
	return (xhash);
}

static char ft_plusspace(const char *input, int j, int nbflag)
{
	char	plusspace;

	if (ft_checktype(input, "+", j, nbflag))
		plusspace = '+';
	else
		plusspace = ' ';
	return (plusspace);
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
		{
//			printf("before space 1 i:%lu\n",i);
			beforestr[i++] = ' ';
		}
	}
	if (str[0] == '-')
		beforestr[i++] = '-';
	else if (ft_checktype(input, " +", j, nbflag))
	{
		beforestr[i++] = ft_plusspace(input, j, nbflag);
	}
	else if ((ft_checktype(input, "#", j, nbflag) && str[0] != '0')
			|| input[j + nbflag] == 'p')
	{	
		beforestr[i++] = '0';
		beforestr[i++] = ft_xhash(input, j, nbflag);
	}
	while (i < ft_beforesize(input, j, nbflag, str))
		beforestr[i++] = '0';
	beforestr[i] = '\0';
	return (beforestr);
}
