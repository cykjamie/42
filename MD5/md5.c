/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:56:33 by chapark           #+#    #+#             */
/*   Updated: 2019/10/16 22:59:31 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void			file_md5(int fd, t_flag *flag)
{
	int		ret;
	char	tmp_buf[65];
	char	*new_copied_buf;

	new_copied_buf = ft_strdup("");
	tmp_buf[64] = 0;
	while ((ret = read(fd, tmp_buf, 64)) > 0)
	{
		tmp_buf[ret] = 0;
		new_copied_buf = ft_strjoin_free(new_copied_buf, tmp_buf);
	}
	flag->s = 1;
	parse_md5(new_copied_buf, flag);
	free(new_copied_buf);
}

void			strin_md5(char *av, unsigned int *old_d, t_flag *flag)
{
	static char			buf[64];
	t_md5				*mddef;
	int					num_block;
	static unsigned int	index = 0;

	mddef = (t_md5*)malloc(sizeof(t_md5));
	ft_bzero(mddef, sizeof(mddef));
	if (ft_strlen(av) == 0)
	{
		get_next_block(-2, &av, buf, flag);
		md5(buf, old_d, mddef);
	}
	else
	{
		num_block = (ft_strlen(av) + 8) / 64 + 1;
		while (num_block--)
		{
			get_block(av, buf, &index);
			get_next_block(-2, &av, buf, flag);
			md5(buf, old_d, mddef);
		}
	}
	index = 0;
	flag->end_str = 1;
	free(mddef);
}

unsigned int	parse_md5(char *av, t_flag *flag)
{
	int				fd;
	unsigned int	old_d[4];
	static char		f_name[1025];
	char			tmp_buf[65];

	fd = open(av, O_RDONLY);
	old_d[0] = 0x67452301;
	old_d[1] = 0xefcdab89;
	old_d[2] = 0x98badcfe;
	old_d[3] = 0x10325476;
	if (av && (flag->s == 1 || flag->std_to_str == 1))
	{
		strin_md5(av, old_d, flag);
		print_md5(old_d, flag, av, f_name);
		return (1);
	}
	if (fd > 0 || flag->all_file)
		return (parse_md5_file(fd, flag, f_name, av));
	if (av != NULL && (!flag->not_std || flag->p || flag->std))
		return (parse_md5_stdin(flag, tmp_buf));
	else
		return (print_error());
	return (0);
}

int				parse_md5_stdin(t_flag *flag, char *tmp_buf)
{
	if (flag->stdin_done == 1)
		return (1);
	flag->not_s = 1;
	stdin_md5(tmp_buf, 0, flag);
	flag->stdin_done = 1;
	return (1);
}

int				parse_md5_file(int fd, t_flag *flag, char *f_name, char *av)
{
	if (fd < 0 && flag->all_file)
	{
		ft_printf("ft_ssl: md5: %s: No such file or directory\n", av);
		return (0);
	}
	flag->file = 1;
	ft_strcpy(f_name, av);
	file_md5(fd, flag);
	close(fd);
	return (1);
}
