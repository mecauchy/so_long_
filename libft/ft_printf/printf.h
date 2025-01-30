/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:30 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/14 13:16:48 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int ft_print_exec(va_list arg, char *format);

int ft_search_s(va_list arg);
int	ft_search_c(va_list arg);
int	ft_search_p(va_list arg);
int	ft_search_d_i(va_list arg);
int	ft_search_u(va_list arg);
int	ft_search_x(va_list arg);
int	ft_search_X(va_list arg);

int    ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putnbr_u(unsigned int n);
int ft_putnbr(int nb);

int	putnbr_hex_x(unsigned int nb);
int	putnbr_hex_X(unsigned int nb);
int	putnbr_hexa_p(void *p);

#endif