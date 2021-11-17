/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:07:58 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/12 12:11:04 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int ft_pointleftz(const char *input, int	j ,const int nbflag, char *str)
{
    char    *nb;
    int     pointnb;
    int     i;
    int     k;

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
static int ft_nbpoint(const char *input, int j ,const int nbflag)
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

static int ft_spacezero(const char *input, int j ,const int nbflag, char *str)
{
	int	spacezero;

	spacezero = ft_nbpoint(input, j, nbflag) - ft_pointleftz(input, j, nbflag, str) - ft_strlen(str);
	if (ft_checktype(input, " +", j, nbflag))
		spacezero -= 1;
	else if (ft_checktype(input, "#", j, nbflag))
		spacezero -= 2;
	if (spacezero < 0)
		return (0);
	return (spacezero);
}

size_t	ft_processflagafter(const char *input, int j, const int nbflag, char *str)
{	
	size_t	nbspaceafter; 
	int 	i;
	
	i = 0;
	nbspaceafter = 0;

	if (ft_checktype(input, "-",j, nbflag))
		nbspaceafter = (size_t)ft_spacezero(input, j, nbflag, str);
	while (i < nbspaceafter)
	{
		write(1, " ", 1);
		i++
	}
	return (nbspaceafter);
}
