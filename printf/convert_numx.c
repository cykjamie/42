/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:14:03 by chapark           #+#    #+#             */
/*   Updated: 2019/05/04 20:14:05 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*convert(unsigned long long num, int base)
{
	char	*ati;
	char	*buff;
	char	*ptr;

	if (num == 0)
		return (ft_strdup("0"));
	ati = "0123456789abcdef";
	buff = (char*)malloc(sizeof(*ptr) * 30);
	buff[29] = '\0';
	ptr = &buff[29];
	while (num != 0)
	{
		ptr--;
		*ptr = ati[num % base];
		num /= base;
	}
	ptr = ft_strdup(ptr);
	free(buff);
	return (ptr);
}

char		*handle_capx(va_list ap, t_fmt *flag)
{
	char	*hex;
	int		i;

	i = 0;
	hex = handle_x(ap, flag);
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		i++;
	}
	return (hex);
}

char		*convert_f(long double n, t_fmt flag)
{
	char		*str;
	char		*tmp;

	if (fpclassify(flag.fvalue) == FP_INFINITE ||
		fpclassify(flag.fvalue) == FP_NAN)
	{
		str = inf_nan(flag);
		return (str);
	}
	if (flag.prec == -1)
		flag.prec = 6;
	f_prec_zero_or_more(&flag);
	n = (long long)flag.fvalue;
	tmp = ft_lltoa(&flag, n);
	str = f_prec_not_zero(flag, tmp);
	while (flag.prec)
	{
		f_prec_convert(&flag, n);
		n = (long long)flag.fvalue;
		tmp = ft_lltoa(&flag, n);
		str = ft_strjoin(str, tmp);
		free(tmp);
		flag.prec--;
	}
	return (str);
}
