/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:14:57 by chapark           #+#    #+#             */
/*   Updated: 2019/05/04 20:14:59 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision(char *ret, t_fmt flag, char sig)
{
	int		len;
	int		negative;

	if (is_diouxp(sig) || sig == 's' || sig == 'f')
	{
		negative = is_negative(&ret, &len);
		len = ft_strlen(ret);
		if (flag.prec != -1 && sig == 's')
		{
			ret = prec_s(ret, flag);
			return (ret);
		}
		if (flag.prec == 0 && flag.value == 0 && sig != 'f')
		{
			ret = prec_zero_value_zero(ret);
			return (ret);
		}
		if (len < flag.prec && is_diouxp(sig))
			ret = prec_diouxp(flag, len, ret);
		zero_width(&ret, negative, flag, sig);
		put_negative_back(&ret, negative);
	}
	return (ret);
}

char	*prec_diouxp(t_fmt flag, int len, char *ret)
{
	char	*tmp;
	void	*dst;

	len = flag.prec - len;
	dst = ft_memalloc(len + 1);
	ft_memset(dst, '0', len);
	tmp = ft_strjoin((char*)dst, ret);
	free(dst);
	free(ret);
	return (tmp);
}

char	*prec_s(char *ret, t_fmt flag)
{
	char *tmp;

	tmp = ft_strdup(ret);
	ret = ft_strsub(tmp, 0, flag.prec);
	free(tmp);
	return (ret);
}

char	*prec_zero_value_zero(char *ret)
{
	free(ret);
	ret = ft_strdup("");
	return (ret);
}
