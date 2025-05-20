/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:33:16 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/09 09:14:39 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*returns data for char string (%s)*/
t_strdata	get_strdata(t_pdata *data)
{
	t_strdata	sdata;

	initialize_strdata(&sdata);
	sdata.str = va_arg(data->ap, char *);
	if (!sdata.str)
	{
		sdata.is_null = true;
		sdata.str = "(null)";
	}
	sdata.len = str_len(sdata.str);
	if (data->fmt.precision && data->fmt.prec_val < sdata.len)
	{
		sdata.truncate = true;
		sdata.len = data->fmt.prec_val;
	}
	if (sdata.truncate && sdata.is_null)
		sdata.len = 0;
	if (data->fmt.width > sdata.len)
		add_padding_strdata(data, &sdata);
	return (sdata);
}

/*returns data for pointer (%p)*/
t_strdata	get_pointerdata(t_pdata *data)
{
	t_strdata	sdata;

	initialize_strdata(&sdata);
	sdata.nptr = (uintptr_t)va_arg(data->ap, void *);
	if (!sdata.nptr)
	{
		sdata.is_null = true;
		sdata.len = 5;
	}
	else
		sdata.len = get_hex_digits(sdata.nptr) + 2;
	if (data->fmt.width > sdata.len)
		add_padding_strdata(data, &sdata);
	return (sdata);
}

void	initialize_strdata(t_strdata *sdata)
{
	b_zero(sdata, sizeof(t_strdata));
}

void	add_padding_strdata(t_pdata *data, t_strdata *sdata)
{
	size_t	padding;

	padding = data->fmt.width - sdata->len;
	if (data->fmt.left_align)
		sdata->after_spaces = padding;
	else
		sdata->before_spaces = padding;
}
