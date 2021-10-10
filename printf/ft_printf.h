/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:48:54 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:48:55 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include "libft/libft.h"

typedef struct			s_fmt
{
	int					width;
	int					prec;
	int					hash;
	int					zero;
	int					left;
	int					plus;
	int					space;
	char				*typelen;
	unsigned long long	value;
	long double			fvalue;
	int					zeroneg;
}						t_fmt;

int						printing(va_list ap, char *sig);
int						ft_printf(const char *restrict fmt, ...);
int						is_conversion(char sig);
t_fmt					fill_fmt(char **sig);
char					*check_type(char *sig, t_fmt *flag);
char					*check_width(char *sig, t_fmt *flag);
char					*check_prec(char *sig, t_fmt *flag);
char					*handle_c(va_list ap, t_fmt *flag);
char					*handle_s(va_list ap, t_fmt *flag);
char					*handle_di(va_list ap, t_fmt *flag);
char					*convert(unsigned long long num, int base);
char					*handle_o(va_list ap, t_fmt *flag);
char					*handle_x(va_list ap, t_fmt *flag);
char					*handle_capx(va_list ap, t_fmt *flag);
char					*handle_u(va_list ap, t_fmt *flag);
char					*handle_p(va_list ap, t_fmt *flag);
char					*handle_percent(va_list ap, t_fmt *flag);
long long				apply_type_di(va_list ap, t_fmt flag);
unsigned long long		apply_type_ouxp(va_list ap, t_fmt flag);
char					*width(char *ret, t_fmt flag, char sig);
char					*precision(char *ret, t_fmt flag, char sig);
int						is_negative(char **ret, int *len);
char					*plus(char *ret, t_fmt flag, char sig);
char					*hash(char *sig, char *str, t_fmt flag);
int						hash_len(char sig, t_fmt flag);
void					zero_width(char **ret, int neg, t_fmt flag, char sig);
void					put_negative_back(char **ret, int negative);
char					*space(char *str, t_fmt flag, char sig);
int						is_diouxp(char sig);
int						is_dif(char sig);
char					*handle_f(va_list ap, t_fmt *flag);
long double				apply_type_f(va_list ap, t_fmt flag);
char					*ft_lltoa(t_fmt *flag, long long n);
char					*convert_f(long double n, t_fmt flag);
void					zero_or_space(t_fmt flag, char sg, void *dst, int ct);
char					*l_or_else(t_fmt flag, void *d, char *r, char s);
char					*prec_zero_value_zero(char *ret);
char					*prec_s(char *ret, t_fmt flag);
char					*prec_diouxp(t_fmt flag, int len, char *ret);
char					*hash_o(char *str);
char					*inf_nan(t_fmt flag);
void					f_prec_zero_or_more(t_fmt *flag);
void					f_prec_convert(t_fmt *flag, long long n);
char					*f_prec_not_zero(t_fmt flag, char *tmp);
int						not_percent(char *sig);
void					add_neg_sign_zeroneg(t_fmt *flag, char *new);
long long				add_neg_sign_neg(long long un, long long n, char *new);

#endif
