/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:22:19 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/30 17:20:33 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

char	*ft_hextoa(unsigned long nb);
char	*ft_hextoap(unsigned long nb);
bool	ft_checkzero(const char *input, int j, int nbflag);
bool	ft_checktype(const char *input, char *set, int start, int nbcheck);
char	*ft_itoua(int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *input, ...);
size_t	ft_argprint(const char *input, va_list args, int j, int nbflag);
char	*ft_argtype(char type, va_list args);
char	*ft_flbefore(const char *input, int j, int nbflag, char *str);
char	ft_plusspace(const char *input, int j, int nbflag);
size_t	ft_flafter(const char *input, int j, int nbflag, char *str);
size_t	ft_flstring(const char *input, int j, int nbflag, char *str);
size_t	ft_nbpoint(const char *input, int j, int nbflag);

#endif
