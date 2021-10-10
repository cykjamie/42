/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hashing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 23:55:48 by chapark           #+#    #+#             */
/*   Updated: 2019/10/14 17:37:29 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

unsigned int	md5_arr_s(int i)
{
	static unsigned int md5_s[64] = {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

	return (md5_s[i]);
}

unsigned int	md5_arr_k(int i)
{
	static unsigned int md5_k[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

	return (md5_k[i]);
}

void			md5_hasing(unsigned int *new_d, unsigned int i,
				unsigned int *f, unsigned int *g)
{
	if (i <= 15)
	{
		*f = (B & C) | ((~B) & D);
		*g = i;
	}
	else if (16 <= i && i <= 31)
	{
		*f = (D & B) | ((~D) & C);
		*g = (5 * i + 1) % 16;
	}
	else if (32 <= i && i <= 47)
	{
		*f = B ^ C ^ D;
		*g = (3 * i + 5) % 16;
	}
	else if (48 <= i && i <= 63)
	{
		*f = C ^ (B | (~D));
		*g = (7 * i) % 16;
	}
}

void			md5_init(unsigned int *old_d, unsigned int *new_d)
{
	A = old_d[0];
	B = old_d[1];
	C = old_d[2];
	D = old_d[3];
}

unsigned int	*md5(char *buf, unsigned int *old_d, t_md5 *mddef)
{
	static unsigned int	new_d[4];
	unsigned int		i;
	unsigned int		f;
	unsigned int		g;

	i = 0;
	ft_memcpy(mddef->mdu.b, buf, 64);
	md5_init(old_d, new_d);
	while (i <= 63)
	{
		md5_hasing(new_d, i, &f, &g);
		f = f + A + md5_arr_k(i) + mddef->mdu.m[g];
		A = D;
		D = C;
		C = B;
		B = B + leftrotate(f, md5_arr_s(i));
		i++;
	}
	old_d[0] += A;
	old_d[1] += B;
	old_d[2] += C;
	old_d[3] += D;
	return (old_d);
}
