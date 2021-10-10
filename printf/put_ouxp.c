/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ouxp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:55:54 by chapark           #+#    #+#             */
/*   Updated: 2019/05/02 23:55:55 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*handle_o(va_list ap, t_fmt *flag)
{
	char				*oct;
	unsigned long long	n;

	n = apply_type_ouxp(ap, *flag);
	flag->value = n;
	oct = convert(n, 8);
	return (oct);
}

char				*handle_x(va_list ap, t_fmt *flag)
{
	char				*hex;
	unsigned long long	n;

	n = apply_type_ouxp(ap, *flag);
	flag->value = n;
	hex = convert(n, 16);
	return (hex);
}

char				*handle_u(va_list ap, t_fmt *flag)
{
	unsigned long long n;

	n = apply_type_ouxp(ap, *flag);
	flag->value = n;
	return (convert(n, 10));
}

char				*handle_p(va_list ap, t_fmt *flag)
{
	char				*hex;
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	flag->value = n;
	hex = convert(n, 16);
	flag->hash = 1;
	return (hex);
}

unsigned long long	apply_type_ouxp(va_list ap, t_fmt flag)
{
	flag.width = 0;
	if (!flag.typelen)
		return (va_arg(ap, unsigned int));
	if (ft_strequ(flag.typelen, "ll"))
		return (va_arg(ap, unsigned long long));
	if (ft_strequ(flag.typelen, "l"))
		return (va_arg(ap, unsigned long));
	if (ft_strequ(flag.typelen, "h"))
		return ((unsigned short)va_arg(ap, unsigned int));
	if (ft_strequ(flag.typelen, "hh"))
		return ((unsigned char)(va_arg(ap, unsigned int)));
	return (0);
}
