/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pritnf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:18:40 by mcauchy-          #+#    #+#             */
/*   Updated: 2024/11/14 11:36:45 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	putnbr_hex_x(unsigned int nb)
{
	int	count;
	char	*base;
	
	count = 0;
	base = "0123456789abcdef";
	if (nb > 16)
	{
		count += ft_putnbr_hexa(nb / 16);
		count += ft_putnbr_hexa(nb % 16);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}

int	putnbr_hex_X(unsigned int nb)
{
	int	count;
	char	*base;
	
	count = 0;
	base = "0123456789ABCDEF";
	if (nb > 16)
	{
		count += ft_putnbr_hexa(nb / 16);
		count += ft_putnbr_hexa(nb % 16);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}

int	putnbr_hexa_p(void *p)
{
	int				count;
	char			*base;
	unsigned long	ptr;

	ptr = (unsigned long)p;
	count = 0;
	base = "0123456789abcdef";
	if (ptr > 16)
	{
		count += ft_putnbr_hexa(ptr / 16);
		count += ft_putnbr_hexa(ptr % 16);
	}
	else
		count += ft_putchar(base[ptr]);
	return (count);
}
