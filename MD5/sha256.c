/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:32:05 by chapark           #+#    #+#             */
/*   Updated: 2019/10/17 01:16:39 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void			file_sha256(int fd, t_flag *flag)
{
	t_sha2	*shadef;
	int		ret;
	char	tmp_buf[65];
	char	*new_copied_buf;

	shadef = (t_sha2*)malloc(sizeof(t_sha2));
	new_copied_buf = ft_strdup("");
	tmp_buf[64] = 0;
	while ((ret = read(fd, tmp_buf, 64)) > 0)
	{
		tmp_buf[ret] = 0;
		new_copied_buf = ft_strjoin_free(new_copied_buf, tmp_buf);
	}
	flag->s = 1;
	parse_sha256(new_copied_buf, shadef, flag);
	free(new_copied_buf);
	free(shadef);
}

void			strin_sha256(char *av, t_sha2 *sha2, t_flag *flag)
{
	static char	buf[64];
	// t_sha2		*shadef;
	int			num_block;
	static unsigned int	index = 0;

	// shadef = (t_sha2*)malloc(sizeof(t_sha2));
	// ft_bzero(shadef, sizeof(shadef));
	if (ft_strlen(av) == 0)
	{
		sha256_get_next_block(-2, &av, buf, flag);
		sha256(buf, sha2, sha2);
	}
	else
	{
		num_block = (ft_strlen(av) + 8) / 64 + 1;
		while (num_block--)
		{
			get_block(av, buf, &index);
			sha256_get_next_block(-2, &av, buf, flag);
			sha256(buf, sha2, sha2);
		}
	}
	index = 0;
	flag->end_str = 1;
	// free(sha2);
}

unsigned int	parse_sha256(char *av, t_sha2 *sha2, t_flag *flag)
{
	int				fd;
	static char		f_name[1025];
	char			tmp_buf[65];

	
	fd = open(av, O_RDONLY);
	sha2->sha_d = (unsigned int*)malloc(sizeof(unsigned int) * 8);
	sha2->sha_d[0] = 0x6a09e667;
	sha2->sha_d[1] = 0xbb67ae85;
	sha2->sha_d[2] = 0x3c6ef372;
	sha2->sha_d[3] = 0xa54ff53a;
	sha2->sha_d[4] = 0x510e527f;
	sha2->sha_d[5] = 0x9b05688c;
	sha2->sha_d[6] = 0x1f83d9ab;
	sha2->sha_d[7] = 0x5be0cd19; 

	if (av && (flag->s == 1 || flag->std_to_str == 1))
	{
		strin_sha256(av, sha2, flag);
		print_sha256(sha2, flag, av, f_name);
		return (1);
	}
	if (fd > 0 || flag->all_file)
		return (parse_sha256_file(fd, flag, f_name, av));
	if (av != NULL && (!flag->not_std || flag->p || flag->std))
		return (parse_sha256_stdin(flag, sha2, tmp_buf));
	else
		return (print_error());
	free(sha2->sha_d);
	return (0);
}

unsigned int	*sha256(char *buf, t_sha2 *sha2, t_sha2 *shadef)
{
	static unsigned int new_d[8];

	sha256_init(new_d, sha2);
	sha256_union(shadef, buf);
	sha256_extend_word(shadef);
	sha2->a = sha2->sha_d[0];
	sha2->b = sha2->sha_d[1];
	sha2->c = sha2->sha_d[2];
	sha2->d = sha2->sha_d[3];
	sha2->e = sha2->sha_d[4];
	sha2->f = sha2->sha_d[5];
	sha2->g = sha2->sha_d[6];
	sha2->h = sha2->sha_d[7];
	sha256_hashing_loop(sha2, shadef);
	sha2->sha_d[0] += sha2->a;
	sha2->sha_d[1] += sha2->b;
	sha2->sha_d[2] += sha2->c;
	sha2->sha_d[3] += sha2->d;
	sha2->sha_d[4] += sha2->e;
	sha2->sha_d[5] += sha2->f;
	sha2->sha_d[6] += sha2->g;
	sha2->sha_d[7] += sha2->h;
	return (sha2->sha_d);
}

void			sha256_hashing(t_sha2 *sha2, t_sha2 *shadef, int i)
{
	unsigned int	s[2];
	unsigned int	tmp[2];
	unsigned int	ch;
	unsigned int	maj;

	s[1] = (r_rot(sha2->e, 6)) ^ (r_rot(sha2->e, 11)) ^ (r_rot(sha2->e, 25));
	ch = (sha2->e & sha2->f) ^ ((~sha2->e) & sha2->g);
	tmp[0] = sha2->h + s[1] + ch + sha256_k(i) + shadef->shau.w[i];
	s[0] = (r_rot(sha2->a, 2)) ^ (r_rot(sha2->a, 13)) ^ (r_rot(sha2->a, 22));
	maj = (sha2->a & sha2->b) ^ (sha2->a & sha2->c) ^ (sha2->b & sha2->c);
	tmp[1] = s[0] + maj;
	sha2->h = sha2->g;
	sha2->g = sha2->f;
	sha2->f = sha2->e;
	sha2->e = sha2->d + tmp[0];
	sha2->d = sha2->c;
	sha2->c = sha2->b;
	sha2->b = sha2->a;
	sha2->a = tmp[0] + tmp[1];
}
