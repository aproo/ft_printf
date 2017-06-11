/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <vmakahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:57:31 by vlad              #+#    #+#             */
/*   Updated: 2017/04/03 09:26:45 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <wchar.h>
# include <wctype.h>
# include <inttypes.h>
# include <stdint.h>

# define ERROR	1
# define OK		0

# define H		1
# define HH		2
# define L		3
# define LL		4
# define J		5
# define Z		6

typedef struct	s_string
{
	const char	*str;
	size_t		current_index;
	size_t		count_print;
	int			error;
}				t_string;

typedef struct	s_flags
{
	int			left_justify;
	int			sign;
	int			space;
	int			fill_zeros;
	int			hashtag;
}				t_flags;

typedef struct	s_data
{
	t_flags		flags;
	int			width;
	int			precision;
	int			set_precision;
	int			lenght;
	char		specifier;
	size_t		free;
}				t_data;

int				ft_printf(const char *format, ...);
void			search_specificars(va_list *args, t_string *rsrc);

const char		*current_str(t_string rsrc, int index);
void			ft_szero(t_string *rsrc, t_data *convert, t_flags *flags);

void			analyze_specificar(va_list *args, t_string *rsrc);
int				check_all(va_list *args, t_string *rsrc, t_data *convert);
int				error(t_string *rsrc, t_data *convert);
int				ft_it_is_spec(char ch);
void			rec_count_print(t_string *rsrc, void *ptr);

int				search_flags(t_string *rsrc, t_flags *flags);
int				search_width(va_list *args, t_string *rsrc, t_data *convert);
int				search_precision(va_list *args, t_string *rsrc,
					t_data *convert);
int				search_length(t_string *rsrc, t_data *convert, char ch);
int				identify_specifiers(t_string *rsrc, t_data *convert);

void			print_struct(t_string *rsrc, t_data *convert, t_flags *flags);
void			print_result(va_list *args, t_string *rsrc, t_data *convert);
char			*choose_specifiers(va_list *args, t_string *rsrc,
					t_data *convert, char sp);
char			*create_str_decimal(t_data *convert, va_list *args);
void			set_flags_decimal(char sp, t_flags flags, char **string);
void			set_precision_numbers(t_data *convert, char **string);
void			fill_to_string(size_t size, char ch,
					char **string, size_t sign);

char			*ft_itoa_uint_max_upper(uintmax_t value, int base);
char			*ft_itoa_uint_max(uintmax_t value, int base);
char			*ft_itoa_int_max(intmax_t value, int base);
int				ft_int_power(int nb, int power);
int				ft_binary_to_decimal(char *str);
char			*ft_str_reverse(char **str);

char			*create_str_octal(t_data *convert, va_list *args);
char			*create_str_hexadecimal(t_data *convert, va_list *args);

char			*create_str_string(t_data *convert, char *str);
char			*set_precision_str(t_data *convert, char *str);
char			*set_precision_str_wide(t_data *convert,
					char *str, int j, int x);
char			*create_str_string_wide(t_string *rsrc,
						t_data *convert, wchar_t *str);
char			*create_chars_wide(t_data *convert, wchar_t *str);
char			*set_width_str(t_data *convert, char *str);
char			*set_width_str_wide(t_data *convert, char *str);
void			convert_without_enter(char **str);
void			convert_with_enter(char **result, wchar_t *str);
size_t			amount_enters(char *str);

void			create_char(t_string *rsrc, t_data *convert, unsigned char ch);
char			*create_str_char_wide(t_string *rsrc,
					t_data *convert, wchar_t ch);
char			*convert_utf8(char **sch, size_t len, size_t byte);
char			*convert_char(wchar_t ch, size_t len, int i, int div);
char			*first_byte(size_t len, char *first_byte);
char			*other_byte(char *other_byte);
char			*edit_bytes(char *sch, char **str, size_t len);
char			*convert_to_integer(char **str, size_t len);
void			check_width_numbers(t_data *convert, char **string,
						size_t width, size_t sign);
void			ft_free_double_array(char ***str);

void			add_fix_main(t_string *rsrc, t_data *convert);

char			*create_str_pointer(t_data *convert, void *pointer);
void			set_precision_pointer(t_data *convert, char **result);

#endif
