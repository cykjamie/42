/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chapark <chapark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:32:53 by chapark           #+#    #+#             */
/*   Updated: 2019/10/16 22:58:31 by chapark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define A new_d[0]
# define B new_d[1]
# define C new_d[2]
# define D new_d[3]

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# define BUFF_SIZE 100
# include "../ft_printf/ft_printf.h"

typedef struct		s_cmd
{
	int				md5;
	int				sha256;
}					t_cmd;

typedef struct		s_flag
{
	int				p;
	int				q;
	int				r;
	int				s;
	int				not_std;
	int				std;
	int				not_s;
	int				file;
	int				std_to_str;
	int				end_str;
	int				all_file;
	int				stdin_done;
}					t_flag;

typedef union		u_mon
{
	uint32_t		m[16];
	char			b[64];
}					t_mon;

typedef struct		s_md5
{
	t_mon			mdu;
}					t_md5;

typedef union		u_son
{
	uint32_t		w[64];
	char			b[64];
}					t_son;

typedef struct		s_sha2
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	*sha_d;
	t_son			shau;
	t_flag			flag;
}					t_sha2;

unsigned int		little_en(unsigned int *word);

int					parse_command(char *command, t_cmd *cmd);

int					parse_flag(char *f, t_flag *flag);

char				*parse_input(int ac, char *in, t_flag *flag);

int					get_input(const int fd, char **line);

int					ft_next_line(char **arr, char **line, int fd, int ret);

int					padding(char *tmp, char *buf, unsigned long long totlen);

int					get_next_block(int fd, char **in, char *buf, t_flag *flag);

unsigned int		*md5(char *buf, unsigned int *old_d, t_md5 *mddef);

unsigned int		leftrotate(unsigned int x, unsigned int c);

unsigned int		parse_md5(char *av, t_flag *flag);

unsigned int		sha256_k(int i);

// unsigned int		parse_sha256(char *av, t_sha2 *sha2);
unsigned int	parse_sha256(char *av, t_sha2 *sha2, t_flag *flag);


unsigned int		*sha256(char *buf, t_sha2 *sha2, t_sha2 *shadef);

unsigned int		r_rot(unsigned int x, unsigned int c);

unsigned long long	shalen_big_en(unsigned long long totlen);

// int	sha256_get_next_block(int fd, char **in, char *buf, unsigned long long totlen);
int	sha256_get_next_block(int fd, char **in, char *buf, t_flag *flag);

int					sha256_padding(char *tmp, char *buf, \
					unsigned long long totlen);

void				print_hash_sha256(t_sha2 *sha2);

// void				parse_print(t_sha2 *sha2);

int					std_input(t_cmd *cmd, t_flag *flag, char **av, \
					int i, t_sha2 *sha2);

void	parse_hash(t_cmd *cmd, int i, char **av, t_flag *flag);
// void	parse_hash(t_cmd *cmd, int i, char **av, t_flag *flag, t_sha2 *sha2);


int		stdin_md5(char *tmp_buf, int fd, t_flag *flag);


// int					stdin_sha256(char *tmp_buf, t_sha2 *sha2);
int		stdin_sha256(char *tmp_buf, t_sha2 *sha2, t_flag *flag);


int					parse_padding_length(int len_read, char *buf);

int				get_block(char *av, char *buf, unsigned int *index);


char				*ft_strjoin_free(char *new_copied_buf, char *tmp_buf);

void				generic_parsing(int ac, int i, char **av);
void	generic_parsing(int ac, int i, char **av);


void			file_md5(int fd, t_flag *flag);


void				md5_hasing(unsigned int *new_d, unsigned int i, \
					unsigned int *f, unsigned int *g);

void				md5_init(unsigned int *old_d, unsigned int *new_d);

int					padding_loop(int len_read, unsigned long long *totlen, \
					char *buf);

int					gnb_parse(char **in, char *buf, int len_read);

void				padding_loop_len_zero(int len_read, \
					unsigned long long *totlen, char *buf, int *pad_len, \
					char *tmp);

void				sha256_init(unsigned int *new_d, t_sha2 *sha2);

void				sha256_union(t_sha2 *shadef, char *buf);

void				sha256_extend_word(t_sha2 *shadef);

void				sha256_hashing(t_sha2 *sha2, t_sha2 *shadef, int i);

// void				file_sha256(int fd);
void			file_sha256(int fd, t_flag *flag);


// void				strin_sha256(char *av, t_sha2 *sha2);
void			strin_sha256(char *av, t_sha2 *sha2, t_flag *flag);


void			strin_md5(char *av, unsigned int *old_d, t_flag *flag);

 
void				sha256_hashing_loop(t_sha2 *sha2, t_sha2 *shadef);

int					pad_128(char *tmp, int pad_len, char *buf);

int					pad_64(char *tmp, int pad_len, unsigned long long totlen);


int					strcpy_64(char *buf, char *tmp);

void			print_md5(unsigned int *old_d, t_flag *flag, char *buf, char *f_name);


void	print_hashing_md5(unsigned int *old_d);

int parse_md5_file(int fd, t_flag *flag, char	*f_name, char *av);

void	print_md5_str(unsigned int *old_d, t_flag *flag, char *buf);

int parse_md5_file(int fd, t_flag *flag, char	*f_name, char *av);

void	print_md5_file(unsigned int *old_d, t_flag *flag, char *f_name);

int	parse_md5_stdin(t_flag *flag, char *tmp_buf);

int print_error(void);

// void	gnb_init(char *tmp, int pad_len, unsigned long long totlen, t_flag *flag);
// void	gnb_init(int pad_len, \
// 		unsigned long long totlen, t_flag *flag);

		// void	gnb_init(int *pad_len, \
		// unsigned long long *totlen, t_flag *flag);

void	gnb_init(char tmp[128], int *pad_len, \
		unsigned long long *totlen, t_flag *flag);

// void do_flag_p(t_flag *flag, char *tmp_buf);
// void	do_flag_p(t_flag *flag, char *tmp_buf, t_cmd *cmd);
void	do_flag_p(t_flag *flag, char *tmp_buf, t_cmd *cmd, t_sha2 *sha2);



// void	do_flag_s(t_flag *flag, int i, t_cmd *cmd, char **av);
int	do_flag_s(t_flag *flag, int i, t_cmd *cmd, char **av);
// int	do_flag_s(t_flag *flag, int i, t_cmd *cmd, char **av, t_sha2 *sha2);


int				parse_sha256_file(int fd, t_flag *flag, char *f_name, char *av);

// int				parse_sha256_stdin(t_flag *flag, char *tmp_buf);
int				parse_sha256_stdin(t_flag *flag, t_sha2 *sha2, char *tmp_buf);


void	print_sha256(t_sha2 *sha2, t_flag *flag, char *buf, char *f_name);

void	print_sha256_file(t_sha2 *sha2, t_flag *flag, char *f_name);

void	print_sha256_str(t_sha2 *sha2, t_flag *flag, char *buf);


#endif
