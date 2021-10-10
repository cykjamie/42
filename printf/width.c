/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:49:38 by chapark           #+#    #+#             */
/*   Updated: 2019/05/06 18:49:38 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*width(char *ret, t_fmt flag, char sig)
{
	int		count;
	int		len;
	void	*dst;
	char	*res;

	len = ft_strlen(ret);
	if (len < flag.width)
	{
		count = flag.width - len;
		dst = ft_memalloc(count + 1);
		zero_or_space(flag, sig, dst, count);
		res = l_or_else(flag, dst, ret, sig);
		free(dst);
		free(ret);
		return (res);
	}
	else
		return (ret);
}

char	*l_or_else(t_fmt flag, void *d, char *r, char s)
{
	char	*res;
	int		len;

	len = ft_strlen(r);
	if (flag.left)
	{
		res = ft_strjoin(r, (char*)d);
		if (s == 'c' && flag.value == 0)
			res[0] = '\0';
	}
	else
	{
		res = ft_strjoin((char*)d, r);
		if (s == 'c' && flag.value == 0)
		{
			len = ft_strlen(res) - 1;
			res[len] = '\0';
		}
	}
	return (res);
}

void	zero_or_space(t_fmt flag, char sg, void *dst, int ct)
{
	if (flag.zero && !flag.left && !(is_diouxp(sg) && flag.prec >= 0))
		ft_memset(dst, '0', ct);
	else
		ft_memset(dst, ' ', ct);
}

int		is_diouxp(char sig)
{
	if (sig == 'i' || sig == 'd' || sig == 'o' ||
		sig == 'u' || sig == 'x' || sig == 'X' || sig == 'p')
		return (1);
	return (0);
}
