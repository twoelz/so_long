/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:23:42 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/10 18:17:07 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns data for signed ints (%d or %i)*/
t_numdata	get_numdata(t_pdata *data)
{
	t_numdata	ndata;

	initialize_intdata(&ndata);
	ndata.n = va_arg(data->ap, int);
	if (ndata.n < 0)
		ndata.un = ABS(ndata.n);
	else
		ndata.un = (t_uint)ndata.n;
	ndata.digits = get_digits(ndata.un);
	set_numdata(data, &ndata);
	return (ndata);
}

void	initialize_intdata(t_numdata *ndata)
{
	b_zero(ndata, sizeof(t_numdata));
	ndata->sign_char = '+';
}

void	set_numdata(t_pdata *data, t_numdata *ndata)
{
	bool		negative;

	if (data->fmt.precision && !data->fmt.prec_val && !ndata->un)
		ndata->digits = 0;
	ndata->len = ndata->digits;
	negative = ndata->n < 0;
	if (negative || (data->fmt.sign && !negative) || data->fmt.no_sign)
	{
		ndata->sign = true;
		ndata->len++;
	}
	if (negative)
		ndata->sign_char = '-';
	else if (!negative && data->fmt.no_sign)
		ndata->sign_char = SPACE;
	data->chs = max_abc(data->fmt.width, ndata->len,
			(data->fmt.prec_val + ndata->sign));
	if (data->chs > ndata->len)
		add_padding_ndata(data, ndata);
}

void	add_padding_ndata(t_pdata *data, t_numdata *ndata)
{
	size_t	padding;
	long	precision_dif;

	padding = data->chs - ndata->len;
	if (data->fmt.left_align || data->fmt.precision)
		data->fmt.zero_pad = false;
	if (data->fmt.zero_pad)
		ndata->zeroes = padding;
	precision_dif = data->fmt.prec_val - ndata->digits;
	if (data->fmt.precision && precision_dif > 0)
		ndata->zeroes = precision_dif;
	padding -= ndata->zeroes;
	if (!padding)
		return ;
	if (data->fmt.left_align)
		ndata->after_spaces = padding;
	else
		ndata->before_spaces = padding;
	return ;
}
