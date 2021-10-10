/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:24:06 by chapark           #+#    #+#             */
/*   Updated: 2019/04/29 19:24:08 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_negative_back(char **ret, int negative)
{
	void *tmp;

	if (negative)
	{
		tmp = *ret;
		*ret = ft_strjoin("-", *ret);
		free(tmp);
	}
}

void	zero_width(char **ret, int neg, t_fmt flag, char sig)
{
	if (flag.zero && !(is_diouxp(sig) && flag.prec >= 0))
	{
		if (neg || flag.plus || flag.space)
			flag.width = flag.width - 1;
		if (flag.hash || sig == 'p')
			flag.width = flag.width - hash_len(sig, flag);
		*ret = width(*ret, flag, sig);
	}
}

int		is_negative(char **ret, int *len)
{
	char *tmp;

	if (ret[0][0] == '-')
	{
		*len -= 1;
		tmp = *ret;
		*ret = ft_strdup(*(ret) + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		hash_len(char sig, t_fmt flag)
{
	if (flag.hash || sig == 'p')
	{
		if (sig == 'x' || sig == 'X' || sig == 'p')
			return (2);
		else
			return (1);
	}
	return (0);
}
