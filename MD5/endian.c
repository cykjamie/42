/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 00:24:58 by chapark           #+#    #+#             */
/*   Updated: 2019/10/07 21:51:06 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		little_en(unsigned int *word)
{
	unsigned int	res;

	res = 0;
	res |= (*word & 0xff) << 24;
	res |= ((*word >> 8) & 0xff) << 16;
	res |= ((*word >> 16) & 0xff) << 8;
	res |= (*word >> 24 & 0xff);
	*word = res;
	return (*word);
}

unsigned int		leftrotate(unsigned int x, unsigned int c)
{
	return (x << c) | (x >> (32 - c));
}

unsigned long long	shalen_big_en(unsigned long long totlen)
{
	unsigned long long res;

	res = 0;
	res |= ((totlen & 0xff) << 56);
	res |= ((totlen >> 8) & 0xff) << 48;
	res |= ((totlen >> 16) & 0xff) << 40;
	res |= ((totlen >> 24) & 0xff) << 32;
	res |= ((totlen >> 32) & 0xff) << 24;
	res |= ((totlen >> 40) & 0xff) << 16;
	res |= ((totlen >> 48) & 0xff) << 8;
	res |= ((totlen >> 56) & 0xff);
	totlen = res;
	return (totlen);
}

unsigned int		r_rot(unsigned int x, unsigned int c)
{
	return (x >> c | x << (32 - c));
}
