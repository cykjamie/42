/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:27:53 by chapark           #+#    #+#             */
/*   Updated: 2019/10/17 00:18:26 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

int	sha256_get_next_block(int fd, char **in, char *buf, t_flag *flag)
{
	static char					tmp[128];
	static int					pad_len;
	int							len_read;
	static unsigned long long	totlen = 0;

	gnb_init(tmp, &pad_len, &totlen, flag);
	if (fd < 0 && !in)
		return (-1);
	len_read = ft_strlen(buf);
	if (len_read < 64)
	{
		if (pad_len == 0)
		{
			totlen += len_read;
			buf[len_read] = '\0';
			pad_len = sha256_padding(tmp, buf, totlen);
			return (strcpy_64(buf, tmp));
		}
		if (pad_len == 64)
			return (pad_64(tmp, pad_len, totlen));
		if (pad_len == 128)
			return (pad_128(tmp, pad_len, buf));
	}
	totlen += 64;
	return (1);
}

int	strcpy_64(char *buf, char *tmp)
{
	int i;

	i = 0;
	while (i < 64)
	{
		buf[i] = tmp[i];
		i++;
	}
	return (1);
}

int	pad_64(char *tmp, int pad_len, unsigned long long totlen)
{
	pad_len = 0;
	totlen = 0;
	ft_bzero(tmp, 128);
	return (0);
}

int	pad_128(char *tmp, int pad_len, char *buf)
{
	int i;

	i = 0;
	while (i < 64)
	{
		buf[i] = tmp[64 + i];
		i++;
	}
	pad_len = 64;
	return (1);
}

int	sha256_padding(char *tmp, char *buf, unsigned long long totlen)
{
	int len;

	len = ft_strlen(buf);
	ft_strcpy(tmp, buf);
	if (len < 56)
	{
		tmp[len] = -128;
		*((unsigned long long*)(tmp + 56)) = shalen_big_en(totlen * 8);
		return (64);
	}
	else
	{
		tmp[len] = 0x80;
		*((unsigned long long*)(tmp + 120)) = shalen_big_en(totlen * 8);
		return (128);
	}
}
