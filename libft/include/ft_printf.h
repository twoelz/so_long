/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:15:18 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 14:24:18 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;

/*ft_printf valid flags*/
# define FLAGS "#-+0 "
# define SPECIFIERS "cspdiuxX%"
# define SPACE ' '

/*max digits for 64-bit signed integer (or long)*/
# define MAX_INT_DIGITS 20
# define BUFFER_SIZE 4096

/*
int to absolute unsigned int
casts int to long to avoid overflow
*/
static inline t_uint	ft_abs(int value)
{
	if (value < 0)
		return ((t_uint)(-1 * (long)value));
	else
		return ((t_uint)value);
}

# define ABS ft_abs

/*arg-format*/
typedef struct s_fmt
{
	char	specifier;
	bool	left_align;
	bool	sign;
	bool	no_sign;
	bool	zero_pad;
	bool	hash;
	bool	precision;
	size_t	prec_val;
	size_t	width;

}	t_fmt;

/*arg-format-flags enum*/
typedef enum e_fmt
{
	sentinel = '%',
	left_align = '-',
	sign = '+',
	no_sign = SPACE,
	zero_pad = '0',
	hash = '#',
	precision = '.',
}	t_enum_fmt;

/*printf data*/
typedef struct s_pdata
{
	char		*buf;
	const char	*s;
	va_list		ap;
	size_t		buf_i;
	size_t		printed_chars;
	t_fmt		fmt;
	size_t		chs;
}	t_pdata;

/*number data (int uint hex)*/
typedef struct s_numdata
{
	int			n;
	t_uint		un;
	size_t		digits;
	size_t		len;
	bool		sign;
	bool		print_sign;
	char		sign_char;
	size_t		zeroes;
	size_t		before_spaces;
	size_t		after_spaces;
}	t_numdata;

/*string or pointer data*/
typedef struct s_strdata
{
	char		*str;
	uintptr_t	nptr;
	size_t		len;
	bool		is_null;
	bool		truncate;
	size_t		str_i;
	size_t		before_spaces;
	size_t		after_spaces;
}	t_strdata;

// ft_printf
int			ft_printf(const char *s, ...);

// data_generic OK
void		init_pdata(t_pdata *data, const char *s, char *buf);
void		initialize_buf(t_pdata *data);
void		initialize_fmt(t_pdata *data);

// data_int OK
t_numdata	get_numdata(t_pdata *data);
void		initialize_intdata(t_numdata *ndata);
void		set_numdata(t_pdata *data, t_numdata *ndata);
void		add_padding_ndata(t_pdata *data, t_numdata *ndata);

// data_str OK
t_strdata	get_strdata(t_pdata *data);
t_strdata	get_pointerdata(t_pdata *data);
void		initialize_strdata(t_strdata *sdata);
void		add_padding_strdata(t_pdata *data, t_strdata *sdata);

// data_uint OK
t_numdata	get_uintdata(t_pdata *data);

// parse_flags OK
void		parse_flags(t_pdata *data);
void		add_flag(t_pdata *data);
void		parse_precision(t_pdata *data);

// parse_generic OK
void		parse_argument(t_pdata *data);
void		parse_width(t_pdata *data);
size_t		parse_number(t_pdata *data);

// print_arg_types OK
void		print_arg_c(t_pdata *data);
void		print_strdata(t_pdata *data);
void		print_strdata_str(t_pdata *data, t_strdata *sdata);
void		print_strdata_ptr(t_pdata *data, t_strdata *sdata);
void		print_numdata(t_pdata *data);

// print_buf OK
void		print_buf(t_pdata *data);
void		add_c_buf(t_pdata *data, const char c);
void		add_str_buf(t_pdata *data, const char *str);

// print_buf_number
void		add_uint_buf(t_pdata *data, t_uint un);
void		add_hex_buf(t_pdata *data, uintptr_t un);
void		add_hex_buf_base(t_pdata *data, uintptr_t un, char *base);
void		add_hex_prefix(t_pdata *data, t_numdata *ndata);

// print_generic OK
void		print_arg(t_pdata *data);
void		print_arg_sentinel(t_pdata *data);
void		print_sub_s(t_pdata *data);

// util_data OK
void		b_zero(void *s, size_t n);
size_t		str_len(const char *str);
bool		c_in_str(t_uchar c, const char *s);
bool		is_digit(t_uchar c);

// util_number
int			max_abc(size_t a, size_t b, size_t c);
size_t		get_digits_base(uintptr_t n, size_t base);
size_t		get_digits(t_uint n);
size_t		get_hex_digits(uintptr_t n);
size_t		nbuf_tosize(const char *nbuf);

#endif
