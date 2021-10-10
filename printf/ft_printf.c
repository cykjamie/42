/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:48:39 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:48:41 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dispatch(char *sig, va_list ap, t_fmt *flag)
{
	char *str;
	char *(*func[255])(va_list, t_fmt*);

	func['c'] = &handle_c;
	func['s'] = &handle_s;
	func['p'] = &handle_p;
	func['d'] = &handle_di;
	func['i'] = &handle_di;
	func['o'] = &handle_o;
	func['u'] = &handle_u;
	func['x'] = &handle_x;
	func['X'] = &handle_capx;
	func['%'] = &handle_percent;
	func['f'] = &handle_f;
	str = func[(int)*sig](ap, flag);
	return (str);
}

int		print_sig(va_list ap, char *sig, t_fmt *flag)
{
	char *str;

	str = dispatch(sig, ap, flag);
	str = precision(str, *flag, *sig);
	str = plus(str, *flag, *sig);
	str = hash(sig, str, *flag);
	str = space(str, *flag, *sig);
	str = width(str, *flag, *sig);
	if (*sig == 'c' && flag->value == 0)
	{
		if (flag->width == 0)
			flag->width++;
	}
	else
		flag->width = ft_strlen(str);
	write(1, str, flag->width);
	free(str);
	return (flag->width);
}

int		ft_printf(const char *restrict fmt, ...)
{
	va_list		ap;
	char		*sig;
	int			count;
	t_fmt		flag;

	count = 0;
	sig = (char *)fmt;
	va_start(ap, fmt);
	while (*sig)
	{
		if (*sig != '%')
			count += not_percent(sig);
		else if (*sig == '%')
		{
			sig++;
			flag = fill_fmt(&sig);
			if (sig == NULL || !is_conversion(*sig))
				return (count);
			count += print_sig(ap, sig, &flag);
			ft_bzero(&flag, sizeof(t_fmt));
		}
		sig++;
	}
	va_end(ap);
	return (count);
}
