/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_generic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:13:41 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 14:24:44 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_pdata(t_pdata *data, const char *s, char *buf)
{
	data->s = s;
	data->buf = buf;
	data->printed_chars = 0;
	initialize_buf(data);
	initialize_fmt(data);
}

void	initialize_buf(t_pdata *data)
{
	b_zero(data->buf, BUFFER_SIZE);
	data->buf_i = 0;
}

void	initialize_fmt(t_pdata *data)
{
	b_zero(&(data->fmt), sizeof(data->fmt));
}
