/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:00:47 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/09 09:48:05 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_uint_buf(t_pdata *data, t_uint un)
{
	int	remainder;

	if (un >= 10)
		add_uint_buf(data, un / 10);
	remainder = (un % 10) + '0';
	add_c_buf(data, remainder);
}

void	add_hex_buf(t_pdata *data, uintptr_t un)
{
	if (data->fmt.specifier == 'X')
		add_hex_buf_base(data, un, "0123456789ABCDEF");
	else
		add_hex_buf_base(data, un, "0123456789abcdef");
}

void	add_hex_buf_base(t_pdata *data, uintptr_t un, char *base)
{
	int	remainder;

	if (un >= 16)
		add_hex_buf_base(data, un / 16, base);
	remainder = (un % 16);
	add_c_buf(data, base[remainder]);
}

void	add_hex_prefix(t_pdata *data, t_numdata *ndata)
{
	const char	specifier = data->fmt.specifier;

	if (!data->fmt.hash || ndata->un == 0)
		return ;
	add_c_buf(data, '0');
	add_c_buf(data, specifier);
}
