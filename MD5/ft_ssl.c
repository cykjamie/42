/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 22:39:02 by chapark           #+#    #+#             */
/*   Updated: 2019/10/17 20:47:55 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

int		main(int ac, char **av)
{
	static int i;

	i = 0;
	if (ac == 1)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	else
	{
		generic_parsing(ac, i, av);
	}
	// system("leaks ft_ssl");
	// while(1)
	// ;
	return (0);
}

void	generic_parsing(int ac, int i, char **av)
{
	t_cmd	cmd;
	t_flag	flag;
	t_sha2	sha2;
	char	tmp_buf[65];

	ft_bzero(&cmd, sizeof(cmd));
	ft_bzero(&flag, sizeof(flag));
	ac -= 1;
	parse_command(av[1], &cmd);
	while (i <= ac)
	{
		parse_flag(av[i], &flag);
		if (flag.s == 1 && av[i] != NULL)
			i = do_flag_s(&flag, i, &cmd, av);
		if (flag.p == 1)
			do_flag_p(&flag, tmp_buf, &cmd, &sha2);
		i++;
	}
	i -= 1;
	if (ac == 1 || !flag.not_std)
		flag.std = 1;
	if (av[i])
		parse_hash(&cmd, i, av, &flag);
}

int	do_flag_s(t_flag *flag, int i, t_cmd *cmd, char **av)
{
	i++;
	parse_hash(cmd, i, av, flag);
	flag->s = 0;
	while (av[++i])
	{
		flag->all_file = 1;
		parse_hash(cmd, i, av, flag);
		flag->s = 0;
	}
	return (i);
}

void	do_flag_p(t_flag *flag, char *tmp_buf, t_cmd *cmd, t_sha2 *sha2)
{
	flag->not_s = 1;
	if (cmd->md5)
		stdin_md5(tmp_buf, 0, flag);
	else if (cmd->sha256)
		stdin_sha256(tmp_buf, sha2, flag);
	flag->stdin_done = 1;
	flag->p = 0;
	flag->std_to_str = 0;
	flag->not_s = 0;
}

void	parse_hash(t_cmd *cmd, int i, char **av, t_flag *flag)
{
	t_sha2 sha2;

	if (cmd->md5)
	{
		if (parse_md5(av[i], flag) > 0)
			i++;
	}
	else if (cmd->sha256 && av[i])
	{
		if (parse_sha256(av[i], &sha2, flag) > 0)
			i++;
	}
}
