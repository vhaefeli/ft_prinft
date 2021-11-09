/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:22:19 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/09 16:34:10 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"

char	*ft_hextoa.c(int nb);

typedef struct s_flags
{
	char	*space;
	char	*hashhex;
