/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:49:21 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:49:22 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_c(va_list ap, t_fmt *flag)
{
	char *c;

	c = ft_memalloc(2);
	*c = va_arg(ap, int);
	flag->value = *c;
	return (c);
}

char	*handle_s(va_list ap, t_fmt *flag)
{
	char *s;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		flag->value = -1;
		return (s);
	}
	else
	{
		s = ft_strdup(s);
		flag->value = -1;
		return (s);
	}
}

char	*handle_percent(va_list ap, t_fmt *flag)
{
	char	*c;

	(void)ap;
	c = ft_memalloc(2);
	*c = '%';
	flag->value = *c;
	return (c);
}

int		not_percent(char *sig)
{
	ft_putchar(*sig);
	return (1);
}
