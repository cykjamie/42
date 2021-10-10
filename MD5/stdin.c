/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 22:35:00 by chapark           #+#    #+#             */
/*   Updated: 2019/10/17 01:14:24 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"
#include <stdio.h>
int		stdin_md5(char *tmp_buf, int fd, t_flag *flag)
{
	t_md5			*mddef;
	int				ret;
	unsigned int	old_d[4];
	char			*new_copied_buf;

	mddef = (t_md5*)malloc(sizeof(t_md5));
	old_d[0] = 0x67452301;
	old_d[1] = 0xefcdab89;
	old_d[2] = 0x98badcfe;
	old_d[3] = 0x10325476;
	new_copied_buf = ft_strdup("");
	tmp_buf[64] = 0;
	while ((ret = read(fd, tmp_buf, 64)) > 0)
	{
		tmp_buf[ret] = 0;
		new_copied_buf = ft_strjoin_free(new_copied_buf, tmp_buf);
	}
	flag->std_to_str = 1;
	parse_md5(new_copied_buf, flag);
	free(new_copied_buf);
	free(mddef);
	return (1);
}

char	*ft_strjoin_free(char *new_copied_buf, char *tmp_buf)
{
	char *res;

	res = ft_strjoin(new_copied_buf, tmp_buf);
	free(new_copied_buf);
	return (res);
}

int		stdin_sha256(char *tmp_buf, t_sha2 *sha2, t_flag *flag)
{
	// t_sha2			*shadef;
	int				ret;
	char			*new_copied_buf;

	// shadef = (t_sha2*)malloc(sizeof(t_sha2));
	free(sha2->sha_d);
	sha2->sha_d = (unsigned int*)malloc(sizeof(unsigned int) * 8);
	sha2->sha_d[0] = 0x6a09e667;
	sha2->sha_d[1] = 0xbb67ae85;
	sha2->sha_d[2] = 0x3c6ef372;
	sha2->sha_d[3] = 0xa54ff53a;
	sha2->sha_d[4] = 0x510e527f;
	sha2->sha_d[5] = 0x9b05688c;
	sha2->sha_d[6] = 0x1f83d9ab;
	sha2->sha_d[7] = 0x5be0cd19;
	new_copied_buf = ft_strdup("");
	tmp_buf[64] = 0;
	while ((ret = read(0, tmp_buf, 64)) > 0)
	{
		tmp_buf[ret] = 0;
		new_copied_buf = ft_strjoin_free(new_copied_buf, tmp_buf);
	}	
	flag->std_to_str = 1;
	parse_sha256(new_copied_buf, sha2, flag);
	// parse_sha256(new_copied_buf, shadef, flag);
	free(new_copied_buf);
	// free(shadef);
	free(sha2->sha_d);
	return (1);
}
