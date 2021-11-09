/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:11 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/08 17:37:34 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static size_t hexlen(int nb)
{
	size_t ln;

	ln = 0;
	while (nb)
	{
		nb = nb / 16;
		ln++;
	}
	return (ln);
}


char	*ft_hextoa(int nb)
{
	char	*hexstr;
	char	*basehex;
	size_t	i;
	
	basehex ="0123456789abcdef";
	i = hexlen(nb);
	hexstr = malloc(i + 1);
		if (!hexstr)
			return (NULL);
	hexstr[i] = '\0';
	i--;
	while (i >= 0)
	{
		printf("i%lu  ",i);
		hexstr[i] = basehex[nb % 16];
		printf("nb %c\n",basehex[nb % 16]);
		nb = nb / 16;
		if (i == 0)
			break;
		i--;
	}
	return (hexstr);
}

int main(void)
{
	int		*add;
	char	*str;
	
	add = 352;
	printf("pointeur: %p\n", &add);
	printf("pointeur en llu: %llu\n", &add);
	str = ft_hextoa(&add);
	printf("%s\n", str);
	free (str);
	return (0);
}
