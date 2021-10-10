/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:48:17 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:48:18 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*f_prec_not_zero(t_fmt flag, char *tmp)
{
	char *str;

	if (flag.prec != 0 || flag.hash)
	{
		str = ft_strjoin(tmp, ".");
		free(tmp);
	}
	else
		str = tmp;
	return (str);
}

void		f_prec_convert(t_fmt *flag, long long n)
{
	flag->fvalue = flag->fvalue - n;
	if (flag->fvalue < 0)
		flag->fvalue = (-1) * (flag->fvalue);
	flag->fvalue = flag->fvalue * 10;
}

void		f_prec_zero_or_more(t_fmt *flag)
{
	int			i;
	long double	roundup;

	if (flag->prec >= 0)
	{
		i = flag->prec;
		roundup = .5;
		while (i)
		{
			roundup /= 10;
			i--;
		}
		if (flag->fvalue < 0)
		{
			flag->fvalue = flag->fvalue - roundup;
			if ((long long)flag->fvalue == 0)
				flag->zeroneg = 1;
		}
		else
			flag->fvalue = flag->fvalue + roundup;
	}
}

char		*inf_nan(t_fmt flag)
{
	char *str;

	if (fpclassify(flag.fvalue) == FP_INFINITE)
		str = ft_strdup("inf");
	if (fpclassify(flag.fvalue) == FP_NAN)
		str = ft_strdup("nan");
	return (str);
}

long double	apply_type_f(va_list ap, t_fmt flag)
{
	flag.width = 0;
	if (!flag.typelen)
		return (va_arg(ap, double));
	if (ft_strequ(flag.typelen, "l"))
		return (va_arg(ap, double));
	if (ft_strequ(flag.typelen, "L"))
		return (va_arg(ap, long double));
	return (0);
}
