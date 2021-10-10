/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:54:12 by chapark           #+#    #+#             */
/*   Updated: 2019/05/02 22:54:20 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handle_di(va_list ap, t_fmt *flag)
{
	char				*di;
	unsigned long long	un;
	long long			n;
	char				*tmp;

	n = apply_type_di(ap, *flag);
	di = NULL;
	if (n < 0)
	{
		un = -(unsigned long long)n;
		flag->value = un;
		tmp = convert(un, 10);
		di = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
	{
		un = (unsigned long long)n;
		flag->value = un;
		di = convert(un, 10);
	}
	return (di);
}

long long	apply_type_di(va_list ap, t_fmt flag)
{
	flag.width = 0;
	if (!flag.typelen)
		return (va_arg(ap, int));
	if (ft_strequ(flag.typelen, "ll"))
		return (va_arg(ap, long long));
	if (ft_strequ(flag.typelen, "l"))
		return (va_arg(ap, long));
	if (ft_strequ(flag.typelen, "h"))
		return ((short)va_arg(ap, int));
	if (ft_strequ(flag.typelen, "hh"))
		return ((char)(va_arg(ap, int)));
	return (0);
}

char		*handle_f(va_list ap, t_fmt *flag)
{
	char		*f;
	long double	n;

	n = apply_type_f(ap, *flag);
	flag->fvalue = n;
	f = convert_f(n, *flag);
	return (f);
}
