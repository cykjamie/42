/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:34:45 by chapark           #+#    #+#             */
/*   Updated: 2019/10/16 22:57:58 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"


void	print_sha256(t_sha2 *sha2, t_flag *flag, char *buf, char *f_name)
{
	int j;

	j = 0;
	if (flag->p)
	{
		ft_printf("%s", buf);
		print_hash_sha256(sha2);
		ft_printf("\n");
	}
	else if (flag->file == 1)
	{
		print_sha256_file(sha2, flag, f_name);
	}
	else if (flag->s == 1 && !flag->p)
	{
		print_sha256_str(sha2, flag, buf);
	}
	else
	{
		print_hash_sha256(sha2);
		ft_printf("\n");
	}
}

void	print_sha256_file(t_sha2 *sha2, t_flag *flag, char *f_name)
{
	if (!flag->r && !flag->q)
		ft_printf("SAH256(%s)= ", f_name);
	print_hash_sha256(sha2);
	if (!flag->r)
		ft_printf("\n");
	if (flag->r && !flag->q)
	{
		ft_printf(" *%s\n", f_name);
	}
	if (flag->r && flag->q)
	{
		ft_printf("\n");
	}
}

void	print_sha256_str(t_sha2 *sha2, t_flag *flag, char *buf)
{
	if (flag->s == 1 && !flag->p && flag->not_s)
	{
		print_hash_sha256(sha2);
		ft_printf("\n");
	}
	else if (flag->r)
	{
		print_hash_sha256(sha2);
		if (!flag->q)
			ft_printf(" \"%s\"", buf);
		ft_printf("\n");
	}
	else if (!flag->q)
	{
		ft_printf("SHA256 (\"%s\") = ", buf);
		print_hash_sha256(sha2);
		ft_printf("\n");
	}
}

void print_hash_sha256(t_sha2 *sha2)
{
	int j;

	j = 0;
	while (j < 8)
	{
		ft_printf("%.8x", sha2->sha_d[j]);
		j++;
	}
}
