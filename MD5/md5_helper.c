/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 01:09:12 by chapark           #+#    #+#             */
/*   Updated: 2019/10/16 23:00:07 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

int		get_next_block(int fd, char **in, char *buf, t_flag *flag)
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
			pad_len = padding(tmp, buf, totlen);
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

void	gnb_init(char tmp[128], int *pad_len, \
		unsigned long long *totlen, t_flag *flag)
{
	ft_bzero(tmp, 128);
	if (flag->end_str == 1)
	{
		*totlen = 0;
		*pad_len = 0;
		flag->end_str = 0;
	}
}

int		padding(char *tmp, char *buf, unsigned long long totlen)
{
	int len;

	len = ft_strlen(buf);
	ft_strcpy(tmp, buf);
	if (len < 56)
	{
		tmp[len] = -128;
		*((unsigned long long*)(tmp + 56)) = totlen * 8;
		return (64);
	}
	else
	{
		tmp[len] = 0x80;
		*((unsigned long long*)(tmp + 120)) = totlen * 8;
		return (128);
	}
}

int		get_block(char *av, char *buf, unsigned int *index)
{
	unsigned int		block_len;

	block_len = 0;
	block_len = ft_strlen(av + *index);
	if (block_len > 64)
		block_len = 64;
	ft_strncpy((char*)buf, (av + *index), 64);
	*index += block_len;
	return (block_len);
}
