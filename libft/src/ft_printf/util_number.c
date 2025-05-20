/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:26:20 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/10 22:27:21 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max_abc(size_t a, size_t b, size_t c)
{
	size_t	result;

	if (a > b)
		result = a;
	else
		result = b;
	if (c > result)
		return (c);
	return (result);
}

/*return number of (base system) digits from a decimal uint*/
size_t	get_digits_base(uintptr_t n, size_t base)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		digits++;
	}
	return (digits);
}

/*return number of decimal digits from a decimal uint*/
size_t	get_digits(t_uint n)
{
	return (get_digits_base(n, 10));
}

/*returns number of hex digits from a decimal uint*/
size_t	get_hex_digits(uintptr_t n)
{
	return (get_digits_base(n, 16));
}

/*
simplified "atoi" for buffer with digit chars
returns size_t instead of int
*/
size_t	nbuf_tosize(const char *nbuf)
{
	size_t	result;

	result = 0;
	while (*nbuf != '\0' && (*nbuf >= '0' && *nbuf <= '9'))
		result = result * 10 + (*nbuf++ - '0');
	return (result);
}
