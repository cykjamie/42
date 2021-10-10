/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:23:06 by chapark           #+#    #+#             */
/*   Updated: 2019/04/29 19:23:08 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_nlen(long long n)
{
	long long	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char				*ft_lltoa(t_fmt *flag, long long n)
{
	long long	un;
	char		*new;
	long		neg;
	long		nlen;

	neg = ((n < 0 || flag->zeroneg) ? 1 : 0);
	un = n;
	nlen = ft_nlen(n);
	new = ft_strnew(nlen + neg);
	if (!new)
		return (NULL);
	if (n < 0)
		un = add_neg_sign_neg(un, n, new);
	if (flag->zeroneg)
		add_neg_sign_zeroneg(flag, new);
	new[nlen + neg] = '\0';
	while (nlen > 0)
	{
		new[nlen + neg - 1] = (un % 10) + '0';
		nlen--;
		un /= 10;
	}
	return (new);
}

void				add_neg_sign_zeroneg(t_fmt *flag, char *new)
{
	new[0] = '-';
	flag->zeroneg = 0;
}

long long			add_neg_sign_neg(long long un, long long n, char *new)
{
	new[0] = '-';
	un = -(unsigned long long)n;
	return (un);
}
