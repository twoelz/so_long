/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:41:58 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/10 18:22:24 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns data for unsigned int (%u, %x, %X)
*set to ignore flags: sign (+) and no_sign (space)
*if hex, gets hex digits*/
t_numdata	get_uintdata(t_pdata *data)

{
	t_numdata	ndata;

	data->fmt.sign = false;
	data->fmt.no_sign = false;
	initialize_intdata(&ndata);
	ndata.un = va_arg(data->ap, t_uint);
	if (data->fmt.specifier == 'u')
		ndata.digits = get_digits(ndata.un);
	else
	{
		ndata.digits = get_hex_digits(ndata.un);
		if (data->fmt.hash && ndata.un)
		{
			ndata.digits += 2;
			data->fmt.prec_val += 2;
		}
	}
	set_numdata(data, &ndata);
	return (ndata);
}
