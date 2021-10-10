/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:45:16 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:45:19 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(char sig)
{
	if (sig == 'i' || sig == 'd' || sig == 'o' ||
	sig == 'u' || sig == 'x' || sig == 'X' || sig == 'f' ||
	sig == 'c' || sig == 's' || sig == 'p' || sig == '%')
		return (1);
	return (0);
}

t_fmt	fill_fmt(char **sig)
{
	t_fmt	flag;

	ft_bzero(&flag, sizeof(flag));
	flag.prec = -1;
	while (**sig && !is_conversion(**sig))
	{
		if (**sig == '#')
			flag.hash = 1;
		if (**sig == '-')
			flag.left = 1;
		if (**sig == '+')
			flag.plus = 1;
		if (**sig == ' ')
			flag.space = 1;
		if (**sig == '0')
			flag.zero = 1;
		*sig = check_type(*sig, &flag);
		*sig = check_width(*sig, &flag);
		*sig = check_prec(*sig, &flag);
		(*sig)++;
	}
	return (flag);
}

char	*check_type(char *sig, t_fmt *flag)
{
	if (*sig == 'h')
	{
		if (sig[1] == 'h')
		{
			flag->typelen = "hh";
			sig++;
		}
		else
			flag->typelen = "h";
	}
	if (*sig == 'l')
	{
		if (*(sig + 1) == 'l')
		{
			flag->typelen = "ll";
			sig++;
		}
		else
			flag->typelen = "l";
	}
	if (*sig == 'L')
		flag->typelen = "L";
	return (sig);
}

char	*check_width(char *sig, t_fmt *flag)
{
	if (*sig >= '1' && *sig <= '9')
	{
		flag->width = ft_atoi(sig);
		while (*sig >= '0' && *sig <= '9')
			sig++;
		sig--;
	}
	return (sig);
}

char	*check_prec(char *sig, t_fmt *flag)
{
	if (*sig == '.')
	{
		sig++;
		if (ft_isdigit(*sig))
			flag->prec = ft_atoi(sig);
		else
			flag->prec = 0;
		while (ft_isdigit(*sig))
			sig++;
		sig--;
	}
	return (sig);
}
