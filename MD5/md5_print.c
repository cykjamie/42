/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:32:35 by chapark           #+#    #+#             */
/*   Updated: 2019/10/16 22:56:31 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void	print_md5(unsigned int *old_d, t_flag *flag, char *buf, char *f_name)
{
	int j;

	j = 0;
	if (flag->p)
	{
		ft_printf("%s", buf);
		print_hashing_md5(old_d);
		ft_printf("\n");
	}
	else if (flag->file == 1)
	{
		print_md5_file(old_d, flag, f_name);
	}
	else if (flag->s == 1 && !flag->p)
	{
		print_md5_str(old_d, flag, buf);
	}
	else
	{
		print_hashing_md5(old_d);
		ft_printf("\n");
	}
}

void	print_md5_file(unsigned int *old_d, t_flag *flag, char *f_name)
{
	if (!flag->r && !flag->q)
		ft_printf("MD5 (%s) = ", f_name);
	print_hashing_md5(old_d);
	if (!flag->r)
		ft_printf("\n");
	if (flag->r && !flag->q)
	{
		ft_printf(" %s\n", f_name);
	}
	if (flag->r && flag->q)
	{
		ft_printf("\n");
	}
}

void	print_md5_str(unsigned int *old_d, t_flag *flag, char *buf)
{
	if (flag->s == 1 && !flag->p && flag->not_s)
	{
		print_hashing_md5(old_d);
		ft_printf("\n");
	}
	else if (flag->r)
	{
		print_hashing_md5(old_d);
		if (!flag->q)
			ft_printf(" \"%s\"", buf);
		ft_printf("\n");
	}
	else if (!flag->q)
	{
		ft_printf("MD5 (\"%s\") = ", buf);
		print_hashing_md5(old_d);
		ft_printf("\n");
	}
}

void	print_hashing_md5(unsigned int *old_d)
{
	int j;

	j = 0;
	little_en(&old_d[0]);
	little_en(&old_d[1]);
	little_en(&old_d[2]);
	little_en(&old_d[3]);
	while (j < 4)
	{
		ft_printf("%.8x", old_d[j]);
		j++;
	}
}

int		print_error(void)
{
	ft_printf("\nerror\n");
	return (0);
}
