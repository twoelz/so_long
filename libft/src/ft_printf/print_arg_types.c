/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:13:50 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 13:21:31 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*prints (%c) format*/
void	print_arg_c(t_pdata *data)
{
	char	c;

	c = (char)va_arg(data->ap, int);
	if (data->fmt.width < 2)
	{
		add_c_buf(data, c);
		return ;
	}
	if (data->fmt.left_align)
		add_c_buf(data, c);
	while (--data->fmt.width)
		add_c_buf(data, SPACE);
	if (!data->fmt.left_align)
		add_c_buf(data, c);
}

/*prints (%s %p) formats*/
void	print_strdata(t_pdata *data)
{
	t_strdata	sdata;
	const bool	is_pointer = data->fmt.specifier == 'p';

	if (is_pointer)
		sdata = get_pointerdata(data);
	else
		sdata = get_strdata(data);
	while (sdata.before_spaces--)
		add_c_buf(data, SPACE);
	if (is_pointer)
		print_strdata_ptr(data, &sdata);
	else
		print_strdata_str(data, &sdata);
	while (sdata.after_spaces--)
		add_c_buf(data, SPACE);
}

void	print_strdata_str(t_pdata *data, t_strdata *sdata)
{
	while (sdata->str_i < sdata->len)
		add_c_buf(data, sdata->str[sdata->str_i++]);
}

void	print_strdata_ptr(t_pdata *data, t_strdata *sdata)
{
	if (sdata->is_null)
	{
		add_str_buf(data, "(nil)");
		return ;
	}
	add_str_buf(data, "0x");
	add_hex_buf(data, sdata->nptr);
}

/*prints (%u %i %d) formats */
void	print_numdata(t_pdata *data)
{
	t_numdata	ndata;
	const char	specifier = data->fmt.specifier;

	if (c_in_str(specifier, "id"))
		ndata = get_numdata(data);
	else
		ndata = get_uintdata(data);
	while (ndata.before_spaces--)
		add_c_buf(data, SPACE);
	if (ndata.sign)
		add_c_buf(data, ndata.sign_char);
	if (c_in_str(specifier, "xXp"))
		add_hex_prefix(data, &ndata);
	while (ndata.zeroes--)
		add_c_buf(data, '0');
	if (ndata.digits && c_in_str(specifier, "diu"))
		add_uint_buf(data, ndata.un);
	else if (ndata.digits && c_in_str(specifier, "xXp"))
		add_hex_buf(data, ndata.un);
	while (ndata.after_spaces--)
		add_c_buf(data, SPACE);
}
