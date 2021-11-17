/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:22:19 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/17 18:25:42 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"

char	*ft_hextoa.c(long long nb);
bool	ft_checktype(char *input, char *set, int start, int nbcheck);
char	*ft_itoua(int n);
int		ft_printf(char const *input, ...);
int		ft_processargprint(const char *input, va_list args, int j, int nbflag);
char	*ft_processargtype(char type, va_list args);
char	*ft_processflagbefore(const char *input, int j, int nbflag, char *str);
size_t	ft_processflagafter(const char *input, int j, int nbflag, char *str);

#endif
