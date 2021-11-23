/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flafter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:37:13 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/23 14:44:29 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointleftz(const char *input, int j, int nbflag, char *str)
{
	char	*nb;
	size_t		pointnb;
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

	spacezero = ft_nbpoint(input, j, nbflag)
		- ft_pointleftz(input, j, nbflag, str) - ft_strlen(str);
//	printf("nbpoint %lu,pointleftz %i strlen %lu = spacezero after: %li\n",ft_nbpoint(input, j, nbflag), ft_pointleftz(input, j, nbflag, str), ft_strlen(str), spacezero);
	if (ft_checktype(input, " +", j, nbflag))
		spacezero -= 1;
	else if (ft_checktype(input, "#", j, nbflag))
		spacezero -= 2;
	if (spacezero < 0)
		return (0);
	return (spacezero);
}

size_t	ft_flafter(const char *input, int j, int nbflag, char *str)
{
	size_t	nbspaceafter;
	size_t	i;
	
	i = 0;
	nbspaceafter = 0;
	if (ft_checktype(input, "-", j, nbflag))
		nbspaceafter = (size_t)ft_spacezero(input, j, nbflag, str);
//	printf("nbspaceafter: %lu\n", nbspaceafter);
	while (i < nbspaceafter)
	{
		write(1, " ", 1);
		i++;
	}
	return (nbspaceafter);
}
