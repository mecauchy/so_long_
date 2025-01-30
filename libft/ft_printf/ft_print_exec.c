/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:04:02 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/13 13:24:54 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_print_exec(va_list arg, char *format)
{
    if (*format == 's')
	  return (ft_search_s(va_arg(arg, char *)));
    if (*format == 'c')
		return (ft_sarch_c(va_arg(arg, char)));
	if (*format == 'p')
		return (ft_search_p(va_arg(arg, void *)));
	if (*format == 'd')
		return (ft_search_d(va_arg(arg, int)));
	if (*format == 'u')
		return (ft_search_u(va_arg(arg, unsigned int)));
}