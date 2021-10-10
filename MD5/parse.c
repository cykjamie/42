/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 22:13:51 by chapark           #+#    #+#             */
/*   Updated: 2019/10/17 00:22:18 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

int	parse_command(char *command, t_cmd *cmd)
{
	if (*command)
	{
		if (ft_strcmp(command, "md5") == 0)
		{
			cmd->md5 = 1;
			return (1);
		}
		if (ft_strcmp(command, "sha256") == 0)
		{
			cmd->sha256 = 1;
			return (1);
		}
	}
	return (0);
}

int	parse_flag(char *f, t_flag *flag)
{
	int i;

	i = 0;
	if (*f)
	{
		while (f[0] == '-' && f[i])
		{
			if (f[i] == 'p')
				flag->p = 1;
			if (f[i] == 'q')
				flag->q = 1;
			if (f[i] == 'r')
				flag->r = 1;
			if (f[i] == 's')
				flag->s = 1;
			i++;
		}
		return (1);
	}
	else
		flag->not_std = 1;
	return (0);
}

int				parse_sha256_file(int fd, t_flag *flag, char *f_name, char *av)
{
	if (fd < 0 && flag->all_file)
	{
		ft_printf("ft_ssl: sha256: %s: No such file or directory\n", av);
		return (0);
	}
	flag->file = 1;
	ft_strcpy(f_name, av);
	file_sha256(fd, flag);
	close(fd);
	return (1);
}

int				parse_sha256_stdin(t_flag *flag, t_sha2 *sha2, char *tmp_buf)
{
	if (flag->stdin_done == 1)
		return (1);
	flag->not_s = 1;
	stdin_sha256(tmp_buf, sha2, flag);
	flag->stdin_done = 1;
	return (1);
}

