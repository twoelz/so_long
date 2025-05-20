/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:03:30 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 12:56:26 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_pdata *data)
{
	while (c_in_str(*data->s, FLAGS))
		add_flag(data);
}

void	add_flag(t_pdata *data)
{
	t_fmt			*fmt;
	const t_uchar	c = *data->s;

	fmt = &data->fmt;
	if (c == left_align)
		fmt->left_align = true;
	else if (c == zero_pad)
		fmt->zero_pad = true;
	else if (c == hash)
		fmt->hash = true;
	else if (c == no_sign)
		fmt->no_sign = true;
	else if (c == sign)
	{
		fmt->sign = true;
		fmt->no_sign = false;
	}
	data->s++;
}

void	parse_precision(t_pdata *data)
{
	data->s++;
	data->fmt.precision = true;
	data->fmt.zero_pad = false;
	data->fmt.prec_val = parse_number(data);
}
