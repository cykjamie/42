/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 15:21:31 by bvilla            #+#    #+#             */
/*   Updated: 2019/01/04 14:37:54 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_printf.h>
#define	 A fflush(stdout); ft_putstr(" ret: "); ft_putnbr(ret); ft_putchar('\n'); fflush(stdin);

void	write_bits(char *s, void *dst)
{
	int		len;
	int		sum;
	int		i;
	int		d;
	int		ofst;

	i = -1;
	d = 0;
	s = ft_strdup(s);
	while (i < 0 || s[i])
	{
		i++;
		if (s[i] && s[i] <= ' ')
		{
			d = 0;
			while (s[i + d] && s[i + d] <= ' ')
				d++;
			s[i] = s[i + d];
			s[i + d] = ' ';
		}
	}
	len = ft_strlen(s);
	sum = 0;
	i = len - 8;
	d = 0;
	ofst = 0;
	while (i >= 0)
	{
		sum = sum * 2 + s[i + ofst] - '0' ;
		i++;
		if (i % 8 == 0)
		{
			((unsigned char*)dst)[d++] = sum;
			sum = 0;
			i -= 16;
			ofst = 0;
		}
	}
}

int main()
{
int		ret;
float	a;
double	b;
long long pointer = 140732903016832;
long double c = -2.0;

  ret = printf("1%#08x", 42); A
  ret = printf("2%#-08x", 42); A
  ret = printf("3@moulitest: %#.x %#.0x", 0, 0); A
  ret = printf("4@moulitest: %.x %.0x", 0, 0); A
  ret = printf("5@moulitest: %5.x %5.0x", 0, 0); A
  ret = printf("6@moulitest: %07.#x %07.x", 0, 0); A
  ret = printf("7%.2s is a string", "this"); A
  ret = printf("8%5.2s is a string", "this"); A
  ret = printf("9%-.2s is a string", "this"); A
  ret = printf("10%-5.2s is a string", "this"); A
 
  ret = printf("11%-05o", 2500); A
  ret = printf("12@moulitest: %.o %.0o", 0, 0); A
  ret = printf("13@moulitest: %5.o %5.0o", 0, 0); A
  ret = printf("14% +d", 42); A
  ret = printf("15%+ d", 42); A
  ret = printf("16%  +d", 42); A
  ret = printf("17%+  d", 42); A
  ret = printf("18% ++d", 42); A
  ret = printf("19%++ d", 42); A
  ret = printf("20%-05d", 42); A
  ret = printf("21%-05d", -42); A
  ret = printf("22@moulitest: %.d %.0d", 0, 0); A
  ret = printf("23@moulitest: %5.d %5.0d", 0, 0); A
  ret = printf("24% u", 4294967295); A

	ret = printf("25%5+0d", 10); A
	ret = printf("26%5+0p", (char*)pointer); A
	ret = printf("27%17+0p", (char*)pointer); A
	ret = printf("28%.17+0p", (char*)pointer); A
	ret = printf("29%p", NULL); A
	ret = printf("30%.17+21+0p", (char*)pointer); A
	ret = printf("31what % 03d", 3); A
	ret = printf("32  "); A
	ret = printf("33%s, %s,", "shit", "mother fucker"); A 
	ret = printf("34%#o", 10); A
	ret = printf("35:%#o", 0); A
	ret = printf("36:%#.3o", 20); A
	ret = printf("36.22:%#.2o", 20); A
	ret = printf("36.44:%#.5o", 20); A
	ret = printf("36.66:%#05o", 20); A
	ret = printf("37:%#04o", 20); A
	ret = printf("36.5:%#.3x", 20); A
	ret = printf("37.5:%#04x", 20); A
	ret = printf("38:%x", (char*)pointer); A
	ret = printf("39:%#X", (char*)pointer); A
	ret = printf("40%-#20x'", (char*)pointer); A
	ret = printf("41%#.20x'", (char*)pointer); A
	ret = printf("42%#17x", (char*)pointer); A
	ret = printf("43BULLSHIT STARTS HERE\n"); A
	ret = printf("44:%#.o", 0); A
	ret = printf("45:%.0o", 0); A
	ret = printf("46:%#.x", 0); A
	ret = printf("47:%#X", 0); A
		//ret = printf("%j% % % "); A
	ret = printf("48%020%"); A
	ret = printf("49%10s is bullshit", NULL); A
	ret = printf("50%10p is bullshit", NULL); A
	ret = printf("51%-4.2d'", -1); A
	
	write_bits("0 00000000 00000000000000000000000", &a);
	ret = printf("%f", a); A
	write_bits("1 00000000 00000000000000000000000", &a);
	ret = printf("%f", a); A
	write_bits("0 01111100 00000000000000000000000", &a);
	ret = printf("%.2f", a); A
	write_bits("0 11111111 00000000000000000000000", &a);
	ret = printf("%f", a); A
	write_bits("1 11111111 00000000000000000000000", &a);
	    ret = printf("%f", a); A
	write_bits("1 11111111 10000000000000000000000", &a);
	    ret = printf("%f", a); A

	write_bits("1 11110110 10000001001011111001110", &a);
	ret = printf("what? %f", a); A
	write_bits("0 01111101 10011001100110011001101", &a);
	    ret = printf("%.30f", a); A
	write_bits("0 10000000 10000000000000000000000", &a);
	    ret = printf("%f", a); A
	write_bits("0 01111110 10000000000000000000000", &a);
	    ret = printf("%f", a); A
	write_bits("0 1000001000000000000000000000000", &a);
	    ret = printf("%f", a); A
	write_bits("0 01111101 00000000000000000000000", &a);
	    ret = printf("%f", a); A
	write_bits("00000000 00000000 00000000 00000001", &a);
    ret = printf("%.200f", a); A

	
	
	write_bits("0 11111110 00000000000000000000000", &a);
	ret = printf("big: %.2f", a); A
	
    // write_bits("1 00000000 00000000000000000000001", &a);
    // ret = printf("%.149f\n", a); A
    // write_bits("1 00000000 00000000000000000000001", &a);
    // ret = printf("%.148f\n", a); A
   write_bits("1 00000000 00000000000000000000001", &a);
//     ret = printf("%.147f\n", a); A




//     write_bits("0 00000000000 \
// 				0000000000000000000000000000000000000000000000000001", &b);
//    	ret = printf("%.1074f", b); A
//     write_bits("0 00000000000 \
// 				0000000000000000000000000000000000000000000000000001", &b);
//    	ret = printf("%.1073f", b); A
//   write_bits("0 00000000000 \
// 				0000000100000000000000000000000000000000000000000001", &b);
//    	ret = printf("%.1072f", b); A


// write_bits("0 00000000000\
// 		0000000000000000000000000000000000000000000000000000", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("1 00000000000\
// 	0000000000000000000000000000000000000000000000000000", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("0 11111111111\
// 	0000000000000000000000000000000000000000000000000000", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("1 11111111111\
// 	0000000000000000000000000000000000000000000000000000", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("0 11111111111\
// 	0000000000000000000000000000000000000000000000000001", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("0 11111111111\
// 	1000000000000000000000000000000000000000000000000001", &b);
//    	ret = printf("%.1074f", b); A

// write_bits("0 11111111111\
// 	1111111111111111111111111111111111111111111111111111", &b);
//    	ret = printf("%.1074f", b); A



	ret = printf("big: %.20f", a); A
	ret = printf("big: %080f", a); A
	a = 99.995;
    ret = printf("%.2f", a); A
	a = 99.994;
    ret = printf("%.2f", a); A
	a = 0.109375;
    ret = printf("%.5f", a); A
	a = 0.328125;
    ret = printf("%010f'", a); A
	ret = printf("%-010f'", a); A
	ret = printf("% -010f'", a); A
	ret = printf("% 010f'", a); A
	a = -0.328125;
    ret = printf("%010f'", a); A
    ret = printf("%010.3f'", a); A
    ret = printf("%010.6f'", a); A
	a = 1;
	ret = printf("%.0f", a); A
	ret = printf("%#.0f", a); A
	a = 1.5;
	ret = printf("%.0f", a); A
	ret = printf("%#.0f", a); A
	write_bits("1 0111 1111 1111 111	1100 0000  0000 0000  0000 0000 \
 										0000 0000  0000 0000  0000 0000 \
 										0000 0000  0000 0000", &c);
	ret = printf(" %Lf", c); A
	// write_bits("0 1111 1111 1111 110	1000 0000  0000 0000  0000 0000 \
	// 									0000 0000  0000 0000  0000 0000 \
	// 									0000 0000  0000 0000", &c);
	// ret = printf("bigger: %Lf\n", c); A



	 write_bits("0 0000 0000 0000 000	0000 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("zero: %Lf\n", c); A
	 write_bits("1 0000 0000 0000 000	0000 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("-zero: %Lf\n", c); A

	//  write_bits("1 0000 0000 0000 000	0000 0000  0000 0000  0000 0000 \
	// 		 							0000 0000  0000 0000  0000 0000 \
	// 									0000 0000  0000 0001", &c);
	// ret = printf("denormal: %.16419Lf\n", c); A

	//  write_bits("1 0000 0000 0000 000	1100 0000  0000 0000  0000 0000 \
	// 		 							0000 0000  0000 0000  0000 0000 \
	// 									0000 0000  0000 0001", &c);
	// ret = printf("denormal: %.16419Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	0000 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("-inf: %Lf\n", c); A
	 write_bits("1 1111 1111 1111 111	0000 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0001", &c);
	ret = printf("nan: %Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	0100 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("nan: %Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	1000 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("-inf: %Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	1010 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("nan: %Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	1100 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("nan: %Lf\n", c); A

	 write_bits("1 1111 1111 1111 111	11100 0000  0000 0000  0000 0000 \
			 							0000 0000  0000 0000  0000 0000 \
										0000 0000  0000 0000", &c);
	ret = printf("nan: %Lf\n", c); A

 ret = printf("%.2c", NULL); A


return (0);
}
