/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:22:54 by chapark           #+#    #+#             */
/*   Updated: 2019/04/29 19:22:56 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*plus(char *ret, t_fmt flag, char sig)
{
	char *res;

	if (flag.plus && ret[0] != '-' && (sig == 'd' || sig == 'i' || sig == 'f'))
	{
		res = ft_strjoin("+", ret);
		free(ret);
		return (res);
	}
	return (ret);
}

char	*hash(char *sig, char *str, t_fmt flag)
{
	char *tmp;

	if (flag.hash)
	{
		if (flag.value == 0 && (*sig == 'x' || *sig == 'X'))
			return (str);
		if (*sig == 'o')
			str = hash_o(str);
		if (*sig == 'x' || *sig == 'p')
		{
			tmp = str;
			str = ft_strjoin("0x", str);
			free(tmp);
		}
		if (*sig == 'X')
		{
			tmp = str;
			str = ft_strjoin("0X", str);
			free(tmp);
		}
	}
	return (str);
}

char	*hash_o(char *str)
{
	char *tmp;

	if (str[0] == '0')
		return (str);
	tmp = str;
	str = ft_strjoin("0", str);
	free(tmp);
	return (str);
}

char	*space(char *str, t_fmt flag, char sig)
{
	char *tmp;

	if (flag.space && (str[0] != '-' && str[0] != '+') && is_dif(sig))
	{
		tmp = str;
		str = ft_strjoin(" ", str);
		free(tmp);
	}
	return (str);
}

int		is_dif(char sig)
{
	if (sig == 'i' || sig == 'd' || sig == 'f')
		return (1);
	return (0);
}
