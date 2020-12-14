/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:30:22 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/11/22 18:28:11 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** gcc -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -Iincludes -o main main.c -L. -lft
** gcc -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -Iincludes main.c -L. -lft -o main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"

#define BUFFER_SIZE		1024

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	if (n / 10 != 0)
		ft_putnbr(ft_abs(n / 10));
	ft_putchar(ft_abs(n % 10) + '0');
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
		write(1, str, i);
}

int		ft_strlen_main(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_non_print(char *str)
{
	char			*hexdigit;
	size_t			i;
	char			buffer[BUFFER_SIZE];
	unsigned char	c;

	hexdigit = "0123456789ABCDEF";
	i = 0;
	while (*str)
	{
		if (i >= BUFFER_SIZE - 2)
		{
			write(1, buffer, i);
			i = 0;
		}
		c = (unsigned char)*str++;
		if (c >= 32 && c <= 126)
			buffer[i++] = c;
		else
		{
			buffer[i++] = '\\';
			buffer[i++] = hexdigit[c / 16];
			buffer[i++] = hexdigit[c % 16];
		}
	}
	write(1, buffer, i);
}

char	ft_rot_i(unsigned int i, char c)
{
	if (c >= 'A' && c <= 'Z')
		c = (c + i <= 'Z') ? (c + i) : ('A' + c + i - 'Z' - 1);
	if (c >= 'a' && c <= 'z')
		c = (c + i <= 'z') ? (c + i) : ('a' + c + i - 'z' - 1);
	return (c);
}

int		main(void)
{
//									FT_MEMSET
	int		array_00[10];
	int		ft_array_00[10];
	char	str_00[6];
	char	ft_str_00[6];
	int		i;
//									FT_BZERO
	int		array_01[4] = {1, 1, 1, 1};
	int		ft_array_01[4] = {1, 1, 1, 1};
	char	str_01[] = "aaaHello";
	char	ft_str_01[] = "aaaHello";
//									FT_MEMCPY
	int		array1_02[4] = {1, 1, 1, 1};
	int		ft_array1_02[4] = {1, 1, 1, 1};
	int		array2_02[4] = {2, 2, 2, 2};
	char	*src;
	char	dst_02[] = "Hello world! Hallo Welt!";
	char	ft_dst_02[] = "Hello world! Hallo Welt!";
	char	*result;
//									FT_MEMCCPY
	int		array1_03[4] = {1, 1, 1, 1};
	int		ft_array1_03[4] = {1, 1, 1, 1};
	int		array2_03[5] = {2, -1, 3, 254, 1};
	char	dst_03[] = "Hello world! Hallo Welt!";
	char	ft_dst_03[] = "Hello world! Hallo Welt!";
	void	*result_03;
	void	*ft_result_03;
//									FT_MEMMOVE
	int		array1_04[] = {2, -1, 3, -2, -4};
	int		ft_array1_04[] = {2, -1, 3, -2, -4};
	char	dst_04[] = "Hello world! Hallo Welt!";
//									FT_MEMCHR
	int		array1_05[4] = {-1, 2, -3, 4};
	int		array2_05[4] = {-4, 3, -2, 1};
	char	dst_05[] = "Hello world!-\xb1-Hallo Welt!";
//									FT_MEMCMP
	int		array1_06[4] = {-4, 2, -3, 1};
	int		array2_06[4] = {4, -2, 3, -1};
	int		array3_06[4] = {4, -2, 3, 1};
	int		result_06;
	char	dst_06[] = "Hello\xa0 world!\nHallo\x00 Welt!";
//									FT_STRLEN
//									FT_ISALPHA
//									FT_ISDIGIT
//									FT_ISALNUM
//									FT_ISASCII
//									FT_ISPRINT
//									FT_TOUPPER
//									FT_TOLOWER
//									FT_STRCHR
	char	str_07[] = "Hello world!-\x7e-Hallo Welt!";
//									FT_STRRCHR
	char	str_08[] = "Hello world!-\x7e-Hallo Welt!";
//									FT_STRNCMP
	int		result_09;
	char	str1_09[] = "Hello world\x80\0\nHallo Welt!";
	char	str2_09[] = "Hello world\x01!";
	char	str3_09[] = "Hello world\x80\0!\nHallo Welt!";
//									FT_STRLCPY
	char	dst_10[20] = {0};
	char	ft_dst_10[20] = {0};
//									FT_STRLCAT
	char	dst_11[30] = "Hallo";
	char	ft_dst_11[30] = "Hallo";
//									FT_STRNSTR
	char	*haystack = "Hello wwworld! - Hallo Welt!";
	char	needle[20] = "wworld";
	char	*str_12;
//									FT_ATOI
//									FT_CALLOC
	char	*ptr_char = NULL;
	int		*ptr_int = NULL;
	size_t	*ptr_size_t = NULL;
//									FT_STRDUP
	char	*str_13 = NULL;
//									FT_SUBSTR
	char	*dest;
//									FT_STRJOIN
//									FT_STRTRIM
//									FT_SPLIT
	char	**array_14;
//									FT_ITOA
	char	*number;
//									FT_STRMAPI
//									FT_PUTCHAR_FD
//									FT_PUTSTR_FD
//									FT_PUTENDL_FD
//									FT_PUTNBR_FD



//									FT_MEMSET
	ft_putstr("\t\t\t\t\t\t\tFT_MEMSET\n");
//	memset(NULL, 1, 10 * sizeof(array_00[0]));
//	ft_memset(NULL, 1, 10 * sizeof(ft_array_00[0]));
	ft_putstr("   memset(NULL, 1, 0 * sizeof(array_00[0]))    : ");
	memset(NULL, 1, 0 * sizeof(array_00[0]));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memset(NULL, 1, 0 * sizeof(ft_array_00[0])) : ");
	ft_memset(NULL, 1, 0 * sizeof(ft_array_00[0]));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(ft_array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memset(array_00, 1, 10 * sizeof(array_00[0]))       : ");
	memset(array_00, 1, 10 * sizeof(array_00[0]));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_array_00, 1, 10 * sizeof(ft_array_00[0])) : ");
	ft_memset(ft_array_00, 1, 10 * sizeof(ft_array_00[0]));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(ft_array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memset(array_00, -2, 10 * sizeof(int))    : ");
	memset(array_00, -2, 10 * sizeof(int));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_array_00, -2, 10 * sizeof(int)) : ");
	ft_memset(ft_array_00, -2, 10 * sizeof(int));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(ft_array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memset(array_00, -1, 10 * sizeof(int))    : ");
	memset(array_00, -1, 10 * sizeof(int));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_array_00, -1, 10 * sizeof(int)) : ");
	ft_memset(ft_array_00, -1, 10 * sizeof(int));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(ft_array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memset(array_00, 0, (0))  : ");
	memset(array_00, 0, (0));
	i = 0;
	while (i < 10)
	{
		ft_putnbr(array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_array_00, 0, 0) : ");
	ft_memset(ft_array_00, 0, 0);
	i = 0;
	while (i < 10)
	{
		ft_putnbr(ft_array_00[i++]);
		if (i < 10)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memset(str_00, \'$\', 6 * sizeof(str_00[0]))       : ");
	memset(str_00, '$', 6 * sizeof(str_00[0]));
	i = 0;
	while (i < 6)
		write(1, &str_00[i++], 1);
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_str_00, \'$\', 6 * sizeof(ft_str_00[0])) : ");
	ft_memset(ft_str_00, '$', 6 * sizeof(ft_str_00[0]));
	i = 0;
	while (i < 6)
		write(1, &ft_str_00[i++], 1);
	write(1, "\n", 1);
	ft_putstr("   memset(str_00, \'\\0\', 3 * sizeof(char))    : ");
	memset(str_00, '\0', 3 * sizeof(char));
	i = 0;
	while (i < 6)
		write(1, &str_00[i++], 1);
	write(1, "\n", 1);
	ft_putstr("ft_memset(ft_str_00, \'\\0\', 3 * sizeof(char)) : ");
	ft_memset(ft_str_00, '\0', 3 * sizeof(char));
	i = 0;
	while (i < 6)
		write(1, &ft_str_00[i++], 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_BZERO
	ft_putstr("\t\t\t\t\t\t\tFT_BZERO\n");
//	ft_putstr("   bzero(NULL, 2 * sizeof(array_01[0]))    : ");
//	ft_putstr("ft_bzero(NULL, 2 * sizeof(ft_array_01[0])) : ");
	ft_putstr("   bzero(NULL, (0)) : ");
	bzero(NULL, (0));
	write(1, "\n", 1);
	ft_putstr("ft_bzero(NULL, 0)   : ");
	ft_bzero(NULL, 0);
	write(1, "\n", 1);
	ft_putstr("   bzero(array_01, 2 * sizeof(array_01[0]))       : ");
	bzero(array_01, 2 * sizeof(array_01[0]));
	i = 0;
	while (i < 4)
	{
		ft_putnbr(array_01[i++]);
		if (i < 4)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_bzero(ft_array_01, 2 * sizeof(ft_array_01[0])) : ");
	ft_bzero(ft_array_01, 2 * sizeof(ft_array_01[0]));
	i = 0;
	while (i < 4)
	{
		ft_putnbr(ft_array_01[i++]);
		if (i < 4)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   bzero(array_01, 4 * sizeof(int))    : ");
	bzero(array_01, 4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		ft_putnbr(array_01[i++]);
		if (i < 4)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_bzero(ft_array_01, 4 * sizeof(int)) : ");
	ft_bzero(ft_array_01, 4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		ft_putnbr(ft_array_01[i++]);
		if (i < 4)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   bzero(str_01, 3 * sizeof(str_01[0]))       : ");
	bzero(str_01, 3 * sizeof(str_01[0]));
	i = 0;
	while (i < 9)
		write(1, &str_01[i++], 1);
	write(1, "\n", 1);
	ft_putstr("ft_bzero(ft_str_01, 3 * sizeof(ft_str_01[0])) : ");
	ft_bzero(ft_str_01, 3 * sizeof(ft_str_01[0]));
	i = 0;
	while (i < 9)
		write(1, &ft_str_01[i++], 1);
	write(1, "\n", 1);
	ft_putstr("   bzero(str_01, (0))  : ");
	bzero(str_01, (0));
	i = 0;
	while (i < 9)
		write(1, &str_01[i++], 1);
	write(1, "\n", 1);
	ft_putstr("ft_bzero(ft_str_01, 0) : ");
	ft_bzero(ft_str_01, 0);
	i = 0;
	while (i < 9)
		write(1, &ft_str_01[i++], 1);
	write(1, "\n", 1);
	ft_putstr("   bzero(str_01, 9 * sizeof(char))    : ");
	bzero(str_01, 9 * sizeof(char));
	i = 0;
	while (i < 9)
		write(1, &str_01[i++], 1);
	write(1, "\n", 1);
	ft_putstr("ft_bzero(ft_str_01, 9 * sizeof(char)) : ");
	ft_bzero(ft_str_01, 9 * sizeof(char));
	i = 0;
	while (i < 9)
		write(1, &ft_str_01[i++], 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_MEMCPY
	ft_putstr("\t\t\t\t\t\t\tFT_MEMCPY\n");
/*	ft_putstr("   memcpy : ");
	result = memcpy(dst_02, NULL, 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy : ");
	result = ft_memcpy(dst_02, NULL, 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(ft_array1_02[i++]);
	write(1, "\n", 1);
*/	ft_putstr("   memcpy(NULL, NULL, 8) : ");
	result = memcpy(NULL, NULL, 8);
	if (result == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("   array1_02 : ");
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(NULL, NULL, 8) : ");
	result = ft_memcpy(NULL, NULL, 8);
	if (result == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("ft_array1_02 : ");
	while (i < 4)
		ft_putnbr(ft_array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("   memcpy(NULL, NULL, 0) : ");
	result = memcpy(NULL, NULL, 0);
	if (result == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("   array1_02 : ");
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(NULL, NULL, 0) : ");
	result = ft_memcpy(NULL, NULL, 0);
	if (result == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("ft_array1_02 : ");
	while (i < 4)
		ft_putnbr(ft_array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("   memcpy(array1_02, array2_02, 8)    : ");
	result = memcpy(array1_02, array2_02, 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_array1_02, array2_02, 8) : ");
	result = ft_memcpy(ft_array1_02, array2_02, 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(ft_array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("   memcpy(array1_02, &array1_02[2], 8)       : ");
	result = memcpy(array1_02, &array1_02[2], 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_array1_02, &ft_array1_02[2], 8) : ");
	result = ft_memcpy(ft_array1_02, &ft_array1_02[2], 8);
	if (result == NULL)
		ft_putstr("(null)");
	i = 0;
	while (i < 4)
		ft_putnbr(array1_02[i++]);
	write(1, "\n", 1);
	ft_putstr("\ndst_02 = ");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	src = "Kikou";
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("   memcpy(dst_02, src, 0)    : ");
	result = memcpy(dst_02, src, 0);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_dst_02, src, 0) : ");
	result = ft_memcpy(ft_dst_02, src, 0);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	ft_putstr("   memcpy(dst_02, src, 5)    : ");
	result = memcpy(dst_02, src, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_dst_02, src, 5) : ");
	result = ft_memcpy(ft_dst_02, src, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	ft_putstr("   memcpy(&dst_02[13], dst_02, 5)       : ");
	result = memcpy(&dst_02[13], dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(&ft_dst_02[13], ft_dst_02, 5) : ");
	result = memcpy(&ft_dst_02[13], ft_dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	src = "Hello";
	ft_putstr("   memcpy(dst_02, src, 5)    : ");
	result = memcpy(dst_02, src, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_dst_02, src, 5) : ");
	result = ft_memcpy(ft_dst_02, src, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	ft_putstr("   memcpy(&dst_02[13], dst_02, 5)       : ");
	result = memcpy(&dst_02[13], dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(&ft_dst_02[13], ft_dst_02, 5) : ");
	result = memcpy(&ft_dst_02[13], ft_dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	ft_putstr("   memcpy(dst_02, dst_02, 5)       : ");
	result = memcpy(dst_02, dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_dst_02, ft_dst_02, 5) : ");
	result = memcpy(ft_dst_02, ft_dst_02, 5);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
	ft_putstr("   memcpy(dst_02, dst_02, 0)       : ");
	result = memcpy(dst_02, dst_02, 0);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy(ft_dst_02, ft_dst_02, 0) : ");
	result = memcpy(ft_dst_02, ft_dst_02, 0);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
/*	ft_putstr("   memcpy : ");
	result = memcpy(&dst_02[5], dst_02, 12);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_02);
	write(1, "\n", 1);
	ft_putstr("ft_memcpy : ");
	result = memcpy(&ft_dst_02[5], ft_dst_02, 12);
	if (result == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_02);
	write(1, "\n", 1);
*/
	write(1, "\n", 1);
	write(1, "\n", 1);


//									FT_MEMCCPY
	ft_putstr("\t\t\t\t\t\t\tFT_MEMCCPY\n");
/*	memccpy(NULL, src, 1, 8);
	ft_memccpy(NULL, src, 1, 8);
	memccpy(dst_03, NULL, 1, 8);
	ft_memccpy(dst_03, NULL, 1, 8);
	memccpy(NULL, NULL, -1, sizeof(array1_03));
	ft_memccpy(NULL, NULL, -1, sizeof(ft_array1_03));
*/	ft_putstr("   memccpy(NULL, NULL, 1, 0) : ");
	result_03 = memccpy(dst_03, NULL, 1, 0);
	result_03 = memccpy(NULL, src, 1, 0);
	result_03 = memccpy(NULL, NULL, 1, 0);
	if (result_03 == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("   array1_03 : ");
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy(NULL, NULL, 1, 0) : ");
	result_03 = ft_memccpy(dst_03, NULL, 1, 0);
	result_03 = ft_memccpy(NULL, src, 1, 0);
	result_03 = ft_memccpy(NULL, NULL, 1, 0);
	if (result_03 == NULL)
		ft_putstr("(null) ");
	i = 0;
	ft_putstr("ft_array1_03 : ");
	while (i < 4)
		ft_putnbr(ft_array1_03[i++]);
	write(1, "\n", 1);
	ft_putstr("   memccpy(array1_03, &array2_03[3], -2, 8)    : ");
	memccpy(array1_03, &array2_03[3], -2, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy(ft_array1_03, &array2_03[3], -2, 8) : ");
	ft_result_03 = ft_memccpy(ft_array1_03, &array2_03[3], -2, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(ft_array1_03[i++]);
	result_03 = memccpy(ft_array1_03, &array2_03[3], -2, 8);
	if (result_03 == ft_result_03)
		ft_putstr(" (return same as memccpy)");
	else
		ft_putstr(" (not the same return as memccpy)");
	write(1, "\n", 1);
	ft_putstr("   memccpy(array1_03, &array1_03[2], 1, 8)       : ");
	memccpy(array1_03, &array1_03[2], 1, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy(ft_array1_03, &ft_array1_03[2], 1, 8) : ");
	ft_result_03 = ft_memccpy(ft_array1_03, &ft_array1_03[2], 1, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	result_03 = memccpy(ft_array1_03, &ft_array1_03[2], 1, 8);
	if (result_03 == ft_result_03)
		ft_putstr(" (return same as memccpy)");
	else
		ft_putstr(" (not the same return as memccpy)");
	write(1, "\n", 1);
	ft_putstr("   memccpy(array1_03, &array2_03[3], -2, 8)       : ");
	memccpy(array1_03, &array2_03[3], -2, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy(ft_array1_03, &array2_03[3], -2, 8)    : ");
	ft_result_03 = ft_memccpy(ft_array1_03, &array2_03[3], -2, 8);
	i = 0;
	while (i < 4)
		ft_putnbr(array1_03[i++]);
	result_03 = memccpy(ft_array1_03, &array2_03[3], -2, 8);
	if (result_03 == ft_result_03)
		ft_putstr(" (return same as memccpy)");
	else
		ft_putstr(" (not the same return as memccpy)");
	write(1, "\n", 1);
	ft_putstr("\ndst_03 = ");
	ft_putstr(dst_03);
	write(1, "\n", 1);
	src = "Kikou";
	ft_putstr("   memccpy(dst_03, src, 'K', 0)    : ");
	src = memccpy(dst_03, src, 'K', 0);
	ft_putstr("dst_03 = ");
	ft_putstr(dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	if (src == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(src);
	write(1, "\n", 1);
	src = "Kikou";
	ft_putstr("ft_memccpy(ft_dst_03, src, 'K', 0) : ");
	src = ft_memccpy(ft_dst_03, src, 'K', 0);
	ft_putstr("dst_03 = ");
	ft_putstr(ft_dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	if (src == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(src);
	write(1, "\n", 1);
	src = "Kikou";
	ft_putstr("   memccpy(dst_03, src, '\\0', 10)    : ");
	src = memccpy(dst_03, src, '\0', 10);
	ft_putstr("dst_03 = ");
	ft_putstr(dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	src = "Kikou";
	ft_putstr("ft_memccpy(ft_dst_03, src, '\\0', 10) : ");
	src = ft_memccpy(ft_dst_03, src, '\0', 10);
	ft_putstr("dst_03 = ");
	ft_putstr(ft_dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("   memccpy(&dst_03[6], dst_03, '\\0', 10)       : ");
	src = memccpy(&dst_03[6], dst_03, '\0', 10);
	ft_putstr("dst_03 = ");
	ft_putstr(dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy(&ft_dst_03[6], ft_dst_03, '\\0', 10) : ");
	src = ft_memccpy(&ft_dst_03[6], ft_dst_03, '\0', 10);
	ft_putstr("dst_03 = ");
	ft_putstr(ft_dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	src = "Hello world! Hallo Welt!";
	ft_putstr("   memccpy(dst_03, src, \' \', sizeof(dst_03))       : ");
	src = memccpy(dst_03, src, ' ', sizeof(dst_03));
	ft_putstr("dst_03 = ");
	ft_putstr(dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	src = "Hello world! Hallo Welt!";
	ft_putstr("ft_memccpy(ft_dst_03, src, \' \', sizeof(ft_dst_03)) : ");
	src = ft_memccpy(ft_dst_03, src, ' ', sizeof(ft_dst_03));
	ft_putstr("dst_03 = ");
	ft_putstr(ft_dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("   memccpy(dst_03, src, \'<\', ft_strlen_main(src))    : ");
	src = memccpy(dst_03, src, '<', ft_strlen_main(src));
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	src = "Hello world! Hallo Welt!";
	ft_putstr("ft_memccpy(ft_dst_03, src, \'<\', ft_strlen_main(src)) : ");
	src = ft_memccpy(ft_dst_03, src, ' ', sizeof(ft_dst_03));
	src = ft_memccpy(ft_dst_03, src, '<', ft_strlen_main(src));
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	src = "Pouet!";
	ft_putstr("   memccpy(&dst_03[17], src, \'\\0\', 8)    : ");
	src = memccpy(&dst_03[17], src, '\0', 8);
	ft_putstr("dst_03 = ");
	ft_putstr(dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	ft_putnbr(src[-2]);
	write(1, "\n", 1);
	src = "Pouet!";
	ft_putstr("ft_memccpy(&ft_dst_03[17], src, \'\\0\', 8) : ");
	src = ft_memccpy(&ft_dst_03[17], src, '\0', 8);
	ft_putstr("dst_03 = ");
	ft_putstr(ft_dst_03);
	write(1, "    ", 4);
	ft_putstr("src = ");
	ft_putstr(src);
	ft_putnbr(src[-2]);
	write(1, "\n", 1);
/*	ft_putstr("   memccpy : ");
	result_03 = memccpy(&dst_03[5], dst_03, 12);
	if (result_03 == NULL)
		ft_putstr("(null)");
	ft_putstr(dst_03);
	write(1, "\n", 1);
	ft_putstr("ft_memccpy : ");
	result_03 = memccpy(&ft_dst_03[5], ft_dst_03, 12);
	if (result_03 == NULL)
		ft_putstr("(null)");
	ft_putstr(ft_dst_03);
	write(1, "\n", 1);
*/
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_MEMMOVE
	ft_putstr("\t\t\t\t\t\t\tFT_MEMMOVE\n");
	src = "I don't know what kind of result this will yeld\n";
//	memmove(NULL, &array1_04[1], 4 * sizeof(int));
//	memmove(array1_04, NULL, 4 * sizeof(int));
	ft_putstr("   memmove(NULL, NULL, 0) : ");
	result = memmove(NULL, NULL, 0);
	if (result == NULL)
		ft_putstr("(null)\n");
	ft_putstr("ft_memmove(NULL, NULL, 0) : ");
	result = ft_memmove(NULL, NULL, 0);
	if (result == NULL)
		ft_putstr("(null)\n");
	ft_putstr("   memmove(NULL, NULL, 4 * sizeof(int)) : ");
	result = memmove(NULL, NULL, 4 * sizeof(int));
	if (result == NULL)
		ft_putstr("(null)\n");
	ft_putstr("ft_memmove(NULL, NULL, 4 * sizeof(int)) : ");
	result = ft_memmove(NULL, NULL, 4 * sizeof(int));
	if (result == NULL)
		ft_putstr("(null)\n");
	ft_putstr("   memmove(array1_04, &array1_04[1], 4 * sizeof(int))       : ");
	result = memmove(array1_04, &array1_04[1], 4 * sizeof(int));
	if (result != (char *)array1_04)
		ft_putstr("(wrong return value) ");
	i = 0;
	while (i < 5)
	{
		ft_putnbr(array1_04[i++]);
		if (i < 5)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("ft_memmove(ft_array1_04, &ft_array1_04[1], 4 * sizeof(int)) : ");
	result = ft_memmove(ft_array1_04, &ft_array1_04[1], 4 * sizeof(int));
	if (result != (char *)ft_array1_04)
		ft_putstr("(wrong return value) ");
	i = 0;
	while (i < 5)
	{
		ft_putnbr(ft_array1_04[i++]);
		if (i < 5)
			write(1, ", ", 2);
	}
	write(1, "\n", 1);
	ft_putstr("   memmove(&dst_04[2], dst_04, 9 * sizeof(char)) : ");
	result = memmove(&dst_04[2], dst_04, 9 * sizeof(char));
	if (result != &dst_04[2])
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("ft_memmove(&dst_04[2], dst_04, 9 * sizeof(char)) : ");
	result = ft_memmove(&dst_04[2], dst_04, 9 * sizeof(char));
	if (result != &dst_04[2])
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("   memmove(dst_04, src, 13 * sizeof(char)) : ");
	result = memmove(dst_04, src, 13 * sizeof(char));
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("ft_memmove(dst_04, src, 13 * sizeof(char)) : ");
	result = ft_memmove(dst_04, src, 13 * sizeof(char));
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("   memmove(dst_04, &dst_04[2], 9 * sizeof(char)) : ");
	result = memmove(dst_04, &dst_04[2], 9 * sizeof(char));
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("ft_memmove(dst_04, &dst_04[2], 9 * sizeof(char)) : ");
	result = ft_memmove(dst_04, &dst_04[2], 9 * sizeof(char));
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("   memmove(dst_04, src, sizeof(dst_04) - 1) : ");
	result = memmove(dst_04, src, sizeof(dst_04) - 1);
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_memcpy(dst_04, "Hello world! Hallo Welt!", sizeof(dst_04));
	ft_putstr("ft_memmove(dst_04, src, sizeof(dst_04) - 1) : ");
	result = ft_memmove(dst_04, src, sizeof(dst_04) - 1);
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_putstr("   memmove(dst_04, src, 0) : ");
	result = memmove(dst_04, src, 0);
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
	ft_putstr("ft_memmove(dst_04, src, 0) : ");
	result = ft_memmove(dst_04, src, 0);
	if (result != dst_04)
		ft_putstr("(wrong return value) ");
	ft_putstr(dst_04);
	write(1, "\n", 1);
//	memmove(dst_04, &src[30], sizeof(dst_04) - 1);
//	ft_memmove(dst_04, &src[30], sizeof(dst_04) - 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_MEMCHR
	ft_putstr("\t\t\t\t\t\t\tFT_MEMCHR\n");
//	src = memchr(NULL, 4, sizeof(array1_05));
//	src = ft_memchr(NULL, 4, sizeof(array1_05));
	ft_putstr("   memchr(NULL, 4, 0) : ");
	src = memchr(NULL, 4, 0);
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("ft_memchr(NULL, 4, 0) : ");
	src = ft_memchr(NULL, 4, 0);
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("   memchr(array1_05, 4, sizeof(array1_05)) : ");
	src = memchr(array1_05, 4, sizeof(array1_05));
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("ft_memchr(array1_05, 4, sizeof(array1_05)) : ");
	src = ft_memchr(array1_05, 4, sizeof(array1_05));
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("   memchr(array2_05, -4, sizeof(array2_05)) : ");
	src = memchr(array2_05, -4, sizeof(array2_05));
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("ft_memchr(array2_05, -4, sizeof(array2_05)) : ");
	src = ft_memchr(array2_05, -4, sizeof(array2_05));
	if (src)
		ft_putnbr(*src);
	write(1, "\n", 1);
	ft_putstr("   memchr(dst_05, '\xb1', sizeof(dst_05)) : ");
	src = memchr(dst_05, '\xb1', sizeof(dst_05));
	if (src)
		ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("ft_memchr(dst_05, '\xb1', sizeof(dst_05)) : ");
	src = ft_memchr(dst_05, '\xb1', sizeof(dst_05));
	if (src)
		ft_putstr(src);
	write(1, "\n", 1);
	ft_putstr("   memchr(dst_05, '>', sizeof(dst_05)) : ");
	src = memchr(dst_05, '>', sizeof(dst_05));
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_memchr(dst_05, '>', sizeof(dst_05)) : ");
	src = ft_memchr(dst_05, '>', sizeof(dst_05));
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   memchr(dst_05, *dst_05, 0) : ");
	src = memchr(dst_05, *dst_05, 0);
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_memchr(dst_05, *dst_05, 0) : ");
	src = ft_memchr(dst_05, *dst_05, 0);
	if (src == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_MEMCMP
	ft_putstr("\t\t\t\t\t\t\tFT_MEMCMP\n");
//	result_06 = memcmp(NULL, NULL, sizeof(array1_06));
//	result_06 = ft_memcmp(NULL, NULL, sizeof(array1_06));
	ft_putstr("   memcmp(NULL, NULL, 0) : ");
	result_06 = memcmp(NULL, NULL, 0);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(NULL, NULL, 0) : ");
	result_06 = ft_memcmp(NULL, NULL, 0);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(array1_06, array2_06, sizeof(array1_06)) : ");
	result_06 = memcmp(array1_06, array2_06, sizeof(array1_06));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(array1_06, array2_06, sizeof(array1_06)) : ");
	result_06 = ft_memcmp(array1_06, array2_06, sizeof(array1_06));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(array2_06, array3_06, sizeof(array2_06)) : ");
	result_06 = memcmp(array2_06, array3_06, sizeof(array2_06));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(array2_06, array3_06, sizeof(array2_06)) : ");
	result_06 = ft_memcmp(array2_06, array3_06, sizeof(array2_06));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(&dst_06[2], &dst_06[16], 10 * sizeof(char)) : ");
	result_06 = memcmp(&dst_06[2], &dst_06[16], 10 * sizeof(char));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(&dst_06[2], &dst_06[16], 10 * sizeof(char)) : ");
	result_06 = memcmp(&dst_06[2], &dst_06[16], 10 * sizeof(char));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(&dst_06[2], &dst_06[16], 3 * sizeof(char)) : ");
	result_06 = memcmp(&dst_06[2], &dst_06[16], 3 * sizeof(char));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(&dst_06[2], &dst_06[16], 3 * sizeof(char)) : ");
	result_06 = memcmp(&dst_06[2], &dst_06[16], 3 * sizeof(char));
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(&dst_06[1], &dst_06[15], 1) : ");
	result_06 = memcmp(&dst_06[1], &dst_06[15], 1);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(&dst_06[1], &dst_06[15], 1) : ");
	result_06 = memcmp(&dst_06[1], &dst_06[15], 1);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("   memcmp(&dst_06[1], &dst_06[15], 0) : ");
	result_06 = memcmp(&dst_06[1], &dst_06[15], 0);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	ft_putstr("ft_memcmp(&dst_06[1], &dst_06[15], 0) : ");
	result_06 = memcmp(&dst_06[1], &dst_06[15], 0);
	ft_putnbr(result_06);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRLEN
	ft_putstr("\t\t\t\t\t\t\tFT_STRLEN\n");
//	strlen(NULL);
//	ft_strlen(NULL);
	ft_putstr("   strlen(\"Hello\") : ");
	ft_putnbr(strlen("Hello"));
	write(1, "\n", 1);
	ft_putstr("ft_strlen(\"Hello\") : ");
	ft_putnbr(ft_strlen("Hello"));
	write(1, "\n", 1);
	ft_putstr("   strlen(\"\") : ");
	ft_putnbr(strlen(""));
	write(1, "\n", 1);
	ft_putstr("ft_strlen(\"\") : ");
	ft_putnbr(ft_strlen(""));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_ISALPHA
	ft_putstr("\t\t\t\t\t\t\tFT_ISALPHA\n");
	ft_putstr("   isalpha('a') : ");
	ft_putnbr(isalpha('a'));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha('a') : ");
	ft_putnbr(ft_isalpha('a'));
	write(1, "\n", 1);
	ft_putstr("   isalpha('Z') : ");
	ft_putnbr(isalpha('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha('Z') : ");
	ft_putnbr(ft_isalpha('Z'));
	write(1, "\n", 1);
	ft_putstr("   isalpha('<') : ");
	ft_putnbr(isalpha('<'));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha('<') : ");
	ft_putnbr(ft_isalpha('<'));
	write(1, "\n", 1);
	ft_putstr("   isalpha(71) : ");
	ft_putnbr(isalpha(71));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha(71) : ");
	ft_putnbr(ft_isalpha(71));
	write(1, "\n", 1);
	ft_putstr("   isalpha(255) : ");
	ft_putnbr(isalpha(255));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha(255) : ");
	ft_putnbr(ft_isalpha(255));
	write(1, "\n", 1);
	ft_putstr("   isalpha(3400) : ");
	ft_putnbr(isalpha(3400));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha(3400) : ");
	ft_putnbr(ft_isalpha(3400));
	write(1, "\n", 1);
	ft_putstr("   isalpha(-125) : ");
	ft_putnbr(isalpha(-2));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha(-125) : ");
	ft_putnbr(ft_isalpha(-2));
	write(1, "\n", 1);
	ft_putstr("   isalpha(-420) : ");
	ft_putnbr(isalpha(-420));
	write(1, "\n", 1);
	ft_putstr("ft_isalpha(-420) : ");
	ft_putnbr(ft_isalpha(-420));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_ISDIGIT
	ft_putstr("\t\t\t\t\t\t\tFT_ISDIGIT\n");
	ft_putstr("   isdigit('0') : ");
	ft_putnbr(isdigit('0'));
	write(1, "\n", 1);
	ft_putstr("ft_isdigit('0') : ");
	ft_putnbr(ft_isdigit('0'));
	write(1, "\n", 1);
	ft_putstr("   isdigit('Z') : ");
	ft_putnbr(isdigit('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_isdigit('Z') : ");
	ft_putnbr(ft_isdigit('Z'));
	write(1, "\n", 1);
	ft_putstr("   isdigit(50) : ");
	ft_putnbr(isdigit(50));
	write(1, "\n", 1);
	ft_putstr("ft_isdigit(50) : ");
	ft_putnbr(ft_isdigit(50));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_ISALNUM
	ft_putstr("\t\t\t\t\t\t\tFT_ISALNUM\n");
	ft_putstr("   isalnum('a') : ");
	ft_putnbr(isalnum('a'));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum('a') : ");
	ft_putnbr(ft_isalnum('a'));
	write(1, "\n", 1);
	ft_putstr("   isalnum('Z') : ");
	ft_putnbr(isalnum('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum('Z') : ");
	ft_putnbr(ft_isalnum('Z'));
	write(1, "\n", 1);
	ft_putstr("   isalnum('<') : ");
	ft_putnbr(isalnum('<'));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum('<') : ");
	ft_putnbr(ft_isalnum('<'));
	write(1, "\n", 1);
	ft_putstr("   isalnum(50) : ");
	ft_putnbr(isalnum(50));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum(50) : ");
	ft_putnbr(ft_isalnum(50));
	write(1, "\n", 1);
	ft_putstr("   isalnum('7') : ");
	ft_putnbr(isalnum('7'));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum('7') : ");
	ft_putnbr(ft_isalnum('7'));
	write(1, "\n", 1);
	ft_putstr("   isalnum(3400) : ");
	ft_putnbr(isalnum(3400));
	write(1, "\n", 1);
	ft_putstr("ft_isalnum(3400) : ");
	ft_putnbr(ft_isalnum(3400));
	write(1, "\n", 1);



//									FT_ISASCII
	ft_putstr("\t\t\t\t\t\t\tFT_ISASCII\n");
	ft_putstr("   isascii('a') : ");
	ft_putnbr(isascii('a'));
	write(1, "\n", 1);
	ft_putstr("ft_isascii('a') : ");
	ft_putnbr(ft_isascii('a'));
	write(1, "\n", 1);
	ft_putstr("   isascii('Z') : ");
	ft_putnbr(isascii('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_isascii('Z') : ");
	ft_putnbr(ft_isascii('Z'));
	write(1, "\n", 1);
	ft_putstr("   isascii(128) : ");
	ft_putnbr(isascii(128));
	write(1, "\n", 1);
	ft_putstr("ft_isascii(128) : ");
	ft_putnbr(ft_isascii(128));
	write(1, "\n", 1);
	ft_putstr("   isascii(-1) : ");
	ft_putnbr(isascii(-1));
	write(1, "\n", 1);
	ft_putstr("ft_isascii(-1) : ");
	ft_putnbr(ft_isascii(-1));
	write(1, "\n", 1);
	ft_putstr("   isascii(-255) : ");
	ft_putnbr(isascii(-255));
	write(1, "\n", 1);
	ft_putstr("ft_isascii(-255) : ");
	ft_putnbr(ft_isascii(-255));
	write(1, "\n", 1);
	ft_putstr("   isascii(3400) : ");
	ft_putnbr(isascii(3400));
	write(1, "\n", 1);
	ft_putstr("ft_isascii(3400) : ");
	ft_putnbr(ft_isascii(3400));
	write(1, "\n", 1);



//									FT_ISPRINT
	ft_putstr("\t\t\t\t\t\t\tFT_ISPRINT\n");
	ft_putstr("   isprint('a') : ");
	ft_putnbr(isprint('a'));
	write(1, "\n", 1);
	ft_putstr("ft_isprint('a') : ");
	ft_putnbr(ft_isprint('a'));
	write(1, "\n", 1);
	ft_putstr("   isprint('Z') : ");
	ft_putnbr(isprint('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_isprint('Z') : ");
	ft_putnbr(ft_isprint('Z'));
	write(1, "\n", 1);
	ft_putstr("   isprint(127) : ");
	ft_putnbr(isprint(127));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(127) : ");
	ft_putnbr(ft_isprint(127));
	write(1, "\n", 1);
	ft_putstr("   isprint(31) : ");
	ft_putnbr(isprint(31));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(31) : ");
	ft_putnbr(ft_isprint(31));
	write(1, "\n", 1);
	ft_putstr("   isprint(32) : ");
	ft_putnbr(isprint(32));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(32) : ");
	ft_putnbr(ft_isprint(32));
	write(1, "\n", 1);
	ft_putstr("   isprint(126) : ");
	ft_putnbr(isprint(126));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(126) : ");
	ft_putnbr(ft_isprint(126));
	write(1, "\n", 1);
	ft_putstr("   isprint(-1) : ");
	ft_putnbr(isprint(-1));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(-1) : ");
	ft_putnbr(ft_isprint(-1));
	write(1, "\n", 1);
	ft_putstr("   isprint(3400) : ");
	ft_putnbr(isprint(3400));
	write(1, "\n", 1);
	ft_putstr("ft_isprint(3400) : ");
	ft_putnbr(ft_isprint(3400));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_TOUPPER
	ft_putstr("\t\t\t\t\t\t\tFT_TOUPPER\n");
	ft_putstr("   toupper('a') : ");
	ft_putchar(toupper('a'));
	write(1, "\n", 1);
	ft_putstr("ft_toupper('a') : ");
	ft_putchar(ft_toupper('a'));
	write(1, "\n", 1);
	ft_putstr("   toupper('Z') : ");
	ft_putchar(toupper('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_toupper('Z') : ");
	ft_putchar(ft_toupper('Z'));
	write(1, "\n", 1);
	ft_putstr("   toupper(0) : ");
	ft_putchar(toupper(0));
	write(1, "\n", 1);
	ft_putstr("ft_toupper(0) : ");
	ft_putchar(ft_toupper(0));
	write(1, "\n", 1);
	ft_putstr("   toupper(126) : ");
	ft_putchar(toupper(126));
	write(1, "\n", 1);
	ft_putstr("ft_toupper(126) : ");
	ft_putchar(ft_toupper(126));
	write(1, "\n", 1);
	ft_putstr("   toupper(127) : ");
	ft_putchar(toupper(127));
	write(1, "\n", 1);
	ft_putstr("ft_toupper(127) : ");
	ft_putchar(ft_toupper(127));
	write(1, "\n", 1);
	ft_putstr("   toupper(-1) : ");
	ft_putchar(toupper(-1));
	write(1, "\n", 1);
	ft_putstr("ft_toupper(-1) : ");
	ft_putchar(ft_toupper(-1));
	write(1, "\n", 1);
	ft_putstr("   toupper(3400) : ");
	ft_putchar(toupper(3400));
	write(1, "\n", 1);
	ft_putstr("ft_toupper(3400) : ");
	ft_putchar(ft_toupper(3400));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_TOLOWER
	ft_putstr("\t\t\t\t\t\t\tFT_TOLOWER\n");
	ft_putstr("   tolower('a') : ");
	ft_putchar(tolower('a'));
	write(1, "\n", 1);
	ft_putstr("ft_tolower('a') : ");
	ft_putchar(ft_tolower('a'));
	write(1, "\n", 1);
	ft_putstr("   tolower('Z') : ");
	ft_putchar(tolower('Z'));
	write(1, "\n", 1);
	ft_putstr("ft_tolower('Z') : ");
	ft_putchar(ft_tolower('Z'));
	write(1, "\n", 1);
	ft_putstr("   tolower(0) : ");
	ft_putchar(tolower(0));
	write(1, "\n", 1);
	ft_putstr("ft_tolower(0) : ");
	ft_putchar(ft_tolower(0));
	write(1, "\n", 1);
	ft_putstr("   tolower(126) : ");
	ft_putchar(tolower(126));
	write(1, "\n", 1);
	ft_putstr("ft_tolower(126) : ");
	ft_putchar(ft_tolower(126));
	write(1, "\n", 1);
	ft_putstr("   tolower(127) : ");
	ft_putchar(tolower(127));
	write(1, "\n", 1);
	ft_putstr("ft_tolower(127) : ");
	ft_putchar(ft_tolower(127));
	write(1, "\n", 1);
	ft_putstr("   tolower(-1) : ");
	ft_putchar(tolower(-1));
	write(1, "\n", 1);
	ft_putstr("ft_tolower(-1) : ");
	ft_putchar(ft_tolower(-1));
	write(1, "\n", 1);
	ft_putstr("   tolower(3400) : ");
	ft_putchar(tolower(3400));
	write(1, "\n", 1);
	ft_putstr("ft_tolower(3400) : ");
	ft_putchar(ft_tolower(3400));
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRCHR
	ft_putstr("\t\t\t\t\t\t\tFT_STRCHR\n");
	ft_putstr("str_07 = ");
	ft_putstr(str_07);
	write(1, "\n", 1);
	write(1, "\n", 1);
//	result = strchr(NULL, '\n');
//	result = ft_strchr(NULL, '\n');
	ft_putstr("   strchr(str_07, \'\\n\') : ");
	result = strchr(str_07, '\n');
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strchr(str_07, \'\\n\') : ");
	result = ft_strchr(str_07, '\n');
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strchr(str_07, 72) : ");
	result = strchr(str_07, 72);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strchr(str_07, 72) : ");
	result = ft_strchr(str_07, 72);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strchr(str_07, 0) : ");
	result = strchr(str_07, 0);
	if (result != NULL)
	{
		if (*result == '\0')
			ft_putstr("\\0");
		else
			ft_putstr(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_strchr(str_07, 0) : ");
	result = ft_strchr(str_07, 0);
	if (result != NULL)
	{
		if (*result == '\0')
			ft_putstr("\\0");
		else
			ft_putstr(result);
	}
	write(1, "\n", 1);
	ft_putstr("   strchr(str_07, -130) : ");
	result = strchr(str_07, -130);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strchr(str_07, -130) : ");
	result = strchr(str_07, -130);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strchr(str_07, \'+\') : ");
	result = strchr(str_07, '+');
	if (result == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strchr(str_07, \'+\') : ");
	result = strchr(str_07, '+');
	if (result == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRRCHR
	ft_putstr("\t\t\t\t\t\t\tFT_STRRCHR\n");
	ft_putstr("str_08 = ");
	ft_putstr(str_08);
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_putstr("   strrchr(str_08, \'\\n\') : ");
	result = strrchr(str_08, '\n');
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strrchr(str_08, \'\\n\') : ");
	result = ft_strrchr(str_08, '\n');
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strrchr(str_08, 72) : ");
	result = strrchr(str_08, 72);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strrchr(str_08, 72) : ");
	result = ft_strrchr(str_08, 72);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strrchr(str_08, 0) : ");
	result = strrchr(str_08, 0);
	if (result != NULL)
	{
		if (*result == '\0')
			ft_putstr("\\0");
		else
			ft_putstr(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_strrchr(str_08, 0) : ");
	result = ft_strrchr(str_08, 0);
	if (result != NULL)
	{
		if (*result == '\0')
			ft_putstr("\\0");
		else
			ft_putstr(result);
	}
	write(1, "\n", 1);
	ft_putstr("   strrchr(str_08, -130) : ");
	result = strrchr(str_08, -130);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("ft_strrchr(str_08, -130) : ");
	result = strrchr(str_08, -130);
	if (result != NULL)
		ft_putstr(result);
	write(1, "\n", 1);
	ft_putstr("   strrchr(str_08, '+') : ");
	result = strrchr(str_08, '+');
	if (result == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strrchr(str_08, '+') : ");
	result = strrchr(str_08, '+');
	if (result == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRNCMP
	ft_putstr("\t\t\t\t\t\t\tFT_STRNCMP\n");
	ft_putstr("str1_09 = ");
	ft_putstr_non_print(str1_09);
	write(1, "\\00", 3);
	ft_putstr_non_print(&str1_09[13]);
	ft_putstr("\nstr2_09 = ");
	ft_putstr_non_print(str2_09);
	ft_putstr("\nstr3_09 = ");
	ft_putstr_non_print(str3_09);
	write(1, "\\00", 3);
	ft_putstr_non_print(&str3_09[13]);
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_putstr("   strncmp(str1_09, str2_09, 0) : ");
	result_09 = strncmp(str1_09, str2_09, 0);
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("ft_strncmp(str1_09, str2_09, 0) : ");
	result_09 = ft_strncmp(str1_09, str2_09, 0);
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("   strncmp(str1_09, str2_09, sizeof(str1_09)) : ");
	result_09 = strncmp(str1_09, str2_09, sizeof(str1_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("ft_strncmp(str1_09, str2_09, sizeof(str1_09)) : ");
	result_09 = ft_strncmp(str1_09, str2_09, sizeof(str1_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("   strncmp(str1_09, str2_09, 11) : ");
	result_09 = strncmp(str1_09, str2_09, 11);
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("ft_strncmp(str1_09, str2_09, 11) : ");
	result_09 = ft_strncmp(str1_09, str2_09, 11);
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("   strncmp(str2_09, str3_09, sizeof(str3_09)) : ");
	result_09 = strncmp(str2_09, str3_09, sizeof(str3_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("ft_strncmp(str2_09, str3_09, sizeof(str3_09)) : ");
	result_09 = ft_strncmp(str2_09, str3_09, sizeof(str3_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("   strncmp(str3_09, str1_09, sizeof(str1_09)) : ");
	result_09 = strncmp(str3_09, str1_09, sizeof(str1_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	ft_putstr("ft_strncmp(str3_09, str1_09, sizeof(str1_09)) : ");
	result_09 = ft_strncmp(str3_09, str1_09, sizeof(str1_09));
	ft_putnbr(result_09);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRLCPY
	ft_putstr("\t\t\t\t\t\t\tFT_STRLCPY\n");
	src = "Hello world!";
	ft_putstr("dst_10[20] =\nsrc = ");
	ft_putstr(src);
	write(1, "\n", 1);
	write(1, "\n", 1);
//	ft_putnbr(strlcpy(NULL, NULL, 20));
//	ft_putnbr(ft_strlcpy(NULL, NULL, 20));
//	ft_putnbr(strlcpy(dst_10, NULL, 20));
//	ft_putnbr(ft_strlcpy(dst_10, NULL, 20));
//	ft_putnbr(strlcpy(NULL, src, 20));
//	ft_putnbr(ft_strlcpy(NULL, src, 20));
	ft_putstr("   strlcpy(NULL, src, 0) : ");
	ft_putnbr(strlcpy(NULL, src, 0));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(NULL, src, 0) : ");
	ft_putnbr(ft_strlcpy(NULL, src, 0));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, \"\", 20) : ");
	ft_putnbr(strlcpy(dst_10, "", 20));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, \"\", 20) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, "", 20));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, src, 20) : ");
	ft_putnbr(strlcpy(dst_10, src, 20));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, src, 20) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, src, 20));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, src, 0) : ");
	ft_putnbr(strlcpy(dst_10, src, 0));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, src, 0) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, src, 0));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, src, 1) : ");
	ft_putnbr(strlcpy(dst_10, src, 1));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, src, 1) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, src, 1));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, src, 2) : ");
	ft_putnbr(strlcpy(dst_10, src, 2));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, src, 2) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, src, 2));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	ft_putstr("   strlcpy(dst_10, src, 6) : ");
	ft_putnbr(strlcpy(dst_10, src, 6));
	ft_putstr("   dst_10 = ");
	ft_putstr(dst_10);
	write(1, "\n", 1);
	ft_putstr("ft_strlcpy(dst_10, src, 6) : ");
	ft_putnbr(ft_strlcpy(ft_dst_10, src, 6));
	ft_putstr("   dst_10 = ");
	ft_putstr(ft_dst_10);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRLCAT
	ft_putstr("\t\t\t\t\t\t\tFT_STRLCAT\n");
	src = " Welt! - Hello world!";
	ft_putstr("dst_11[30] = Hallo\nsrc = ");
	ft_putstr(src);
	write(1, "\n", 1);
	write(1, "\n", 1);
//	ft_putnbr(strlcat(NULL, NULL, 0));
//	ft_putnbr(ft_strlcat(NULL, NULL, 0));
//	ft_putnbr(strlcat(dst_11, NULL, 0));
//	ft_putnbr(ft_strlcat(dst_11, NULL, 0));
	ft_putstr("   strlcat(NULL, src, 0) : ");
	ft_putnbr(strlcat(NULL, src, 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(NULL, src, 0) : ");
	ft_putnbr(ft_strlcat(NULL, src, 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	ft_putstr("   strlcat(NULL, \"Hallo\", 0) : ");
	ft_putnbr(strlcat(NULL, "Hallo", 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(NULL, \"Hallo\", 0) : ");
	ft_putnbr(ft_strlcat(NULL, "Hallo", 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	dst_11[0] = '\0';
	ft_dst_11[0] = '\0';
	ft_putstr("   strlcat(dst_11, \" Hallo!\", 0) : ");
	ft_putnbr(strlcat(dst_11, " Hallo!", 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(dst_11, \" Hallo!\", 0) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, " Hallo!", 0));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	dst_11[0] = 'H';
	ft_dst_11[0] = 'H';
	ft_putstr("   strlcat(dst_11, \"\", 20) : ");
	ft_putnbr(strlcat(dst_11, "", 20));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(dst_11, \"\", 20) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, "", 20));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	ft_putstr("   strlcat(dst_11, \"Kikou kikou!\", 2) : ");
	ft_putnbr(strlcat(dst_11, "Kikou kikou!", 2));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(dst_11, \"Kikou kikou!\", 2) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, "Kikou kikou!", 2));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	ft_putstr("   strlcat(dst_11, src, 6) : ");
	ft_putnbr(strlcat(dst_11, src, 6));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(dst_11, src, 6) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, src, 6));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	ft_putstr("   strlcat(dst_11, src, 22) : ");
	ft_putnbr(strlcat(dst_11, src, 22));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_putstr("ft_strlcat(dst_11, src, 22) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, src, 22));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	dst_11[5] = '\0';
	ft_putstr("   strlcat(dst_11, src, 30) : ");
	ft_putnbr(strlcat(dst_11, src, 30));
	ft_putstr("   dst_11 = ");
	ft_putstr(dst_11);
	write(1, "\n", 1);
	ft_dst_11[5] = '\0';
	ft_putstr("ft_strlcat(dst_11, src, 30) : ");
	ft_putnbr(ft_strlcat(ft_dst_11, src, 30));
	ft_putstr("   dst_11 = ");
	ft_putstr(ft_dst_11);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRNSTR
	ft_putstr("\t\t\t\t\t\t\tFT_STRNSTR\n");
	ft_putstr("haystack = ");
	ft_putstr(haystack);
	ft_putstr("\nneedle = ");
	ft_putstr(needle);
	write(1, "\n", 1);
	write(1, "\n", 1);
//	if ((str_12 = strnstr(NULL, needle, 1)) != NULL)
//	if ((str_12 = ft_strnstr(NULL, needle, 1)) != NULL)
//	if ((str_12 = strnstr(haystack, NULL, 0)) != NULL)
//	if ((str_12 = ft_strnstr(haystack, NULL, 0)) != NULL)
	ft_putstr("   strnstr(NULL, needle, 0) : ");
	if ((str_12 = strnstr(NULL, needle, 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(NULL, needle, 0) : ");
	if ((str_12 = ft_strnstr(NULL, needle, 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   strnstr(NULL, \"\", 0) : ");
	if ((str_12 = strnstr(NULL, "", 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(NULL, \"\", 0) : ");
	if ((str_12 = ft_strnstr(NULL, "", 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   strnstr(NULL, \"\", 10) : ");
	if ((str_12 = strnstr(NULL, "", 10)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(NULL, \"\", 10) : ");
	if ((str_12 = ft_strnstr(NULL, "", 10)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   strnstr(haystack, needle, 0) : ");
	if ((str_12 = strnstr(haystack, needle, 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(haystack, needle, 0) : ");
	if ((str_12 = ft_strnstr(haystack, needle, 0)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   strnstr(haystack, \"\", 0) : ");
	if ((str_12 = strnstr(haystack, "", 0)) != NULL)
		ft_putstr(str_12);
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(haystack, \"\", 0) : ");
	if ((str_12 = ft_strnstr(haystack, "", 0)) != NULL)
		ft_putstr(str_12);
	write(1, "\n", 1);
	ft_putstr("   strnstr(haystack, needle, 12) : ");
	if ((str_12 = strnstr(haystack, needle, 12)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(haystack, needle, 12) : ");
	if ((str_12 = ft_strnstr(haystack, needle, 12)) == NULL)
		ft_putstr("(null)");
	write(1, "\n", 1);
	ft_putstr("   strnstr(haystack, needle, 13) : ");
	if ((str_12 = strnstr(haystack, needle, 13)) != NULL)
		ft_putstr(str_12);
	write(1, "\n", 1);
	ft_putstr("ft_strnstr(haystack, needle, 13) : ");
	if ((str_12 = ft_strnstr(haystack, needle, 13)) != NULL)
		ft_putstr(str_12);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_ATOI
	ft_putstr("\t\t\t\t\t\t\tFT_ATOI\n");
	ft_putstr("   atoi( \\t\\n\\v\\f\\r+2147483647) : ");
	ft_putnbr(atoi(" \t\n\v\f\r+2147483647"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi( \\t\\n\\v\\f\\r+2147483647) : ");
	ft_putnbr(ft_atoi(" \t\n\v\f\r+2147483647"));
	ft_putchar('\n');
	ft_putstr("   atoi( \\t+0 22) : ");
	ft_putnbr(atoi(" \t+0 22"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi( \\t+0 22) : ");
	ft_putnbr(ft_atoi(" \t+0 22"));
	ft_putchar('\n');
	ft_putstr("   atoi(---42) : ");
	ft_putnbr(atoi("---42"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(---42) : ");
	ft_putnbr(ft_atoi("---42"));
	ft_putchar('\n');
	ft_putstr("   atoi(\\n+42) : ");
	ft_putnbr(atoi("\n+42"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(\\n+42) : ");
	ft_putnbr(ft_atoi("\n+42"));
	ft_putchar('\n');
	ft_putstr("   atoi(\\t\\n\\v\\f\\r -2147483648 a) : ");
	ft_putnbr(atoi("\t\n\v\f\r -2147483648 a"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(\\t\\n\\v\\f\\r -2147483648 a) : ");
	ft_putnbr(ft_atoi("\t\n\v\f\r -2147483648 a"));
	ft_putchar('\n');
	ft_putstr("   atoi(-2147483650 a) : ");
	ft_putnbr(atoi("-2147483650 a"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(-2147483650 a) : ");
	ft_putnbr(ft_atoi("-2147483650 a"));
	ft_putchar('\n');
	ft_putstr("   atoi(-345678902147483650 a) : ");
	ft_putnbr(atoi("-345678902147483650 a"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(-345678902147483650 a) : ");
	ft_putnbr(ft_atoi("-345678902147483650 a"));
	ft_putchar('\n');
/*	ft_putstr("   atoi(LLONG_MAX + 10) : ");
	ft_putnbr(atoi("9223372036854775817"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(LLONG_MAX + 10) : ");
	ft_putnbr(ft_atoi("9223372036854775817"));
	ft_putchar('\n');
	ft_putstr("   atoi(LLONG_MIN - 10) : ");
	ft_putnbr(atoi("-9223372036854775818"));
	write(1, "\n", 1);
	ft_putstr("ft_atoi(LLONG_MIN - 10) : ");
	ft_putnbr(ft_atoi("-9223372036854775818"));
	ft_putchar('\n');
*/
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_CALLOC
	ft_putstr("\t\t\t\t\t\t\tFT_CALLOC\n");
	ft_putstr("sizeof char : ");
	ft_putnbr(sizeof(char));
	write(1, "\n", 1);
	ft_putstr("sizeof int : ");
	ft_putnbr(sizeof(int));
	write(1, "\n", 1);
	ft_putstr("sizeof size_t : ");
	ft_putnbr(sizeof(size_t));
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_putstr("   calloc(0, sizeof(char)) : ");
	if ((ptr_char = calloc(0, sizeof(char))) != NULL)
	{
//		ft_putnbr(*ptr_char);
		ft_putstr("(not null)");
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("ft_calloc(0, sizeof(char)) : ");
	if ((ptr_char = ft_calloc(0, sizeof(char))) != NULL)
	{
//		ft_putnbr(*ptr_char);
		ft_putstr("(not null)");
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("   calloc(10, 0) : ");
	if ((ptr_char = calloc(10, 0)) != NULL)
	{
//		ft_putnbr(*ptr_char);
		ft_putstr("(not null)");
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("ft_calloc(10, 0) : ");
	if ((ptr_char = ft_calloc(10, 0)) != NULL)
	{
//		ft_putnbr(*ptr_char);
		ft_putstr("(not null)");
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("   calloc(10, sizeof(char)) : ");
	i = 10;
	if ((ptr_char = calloc(i, sizeof(char))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_char[i]);
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("ft_calloc(10, sizeof(char)) : ");
	i = 10;
	if ((ptr_char = ft_calloc(i, sizeof(char))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_char[i]);
		free(ptr_char);
	}
	write(1, "\n", 1);
	ft_putstr("   calloc(10, sizeof(int)) : ");
	i = 10;
	if ((ptr_int = calloc(i, sizeof(int))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_int[i]);
		free(ptr_int);
	}
	write(1, "\n", 1);
	ft_putstr("ft_calloc(10, sizeof(int)) : ");
	i = 10;
	if ((ptr_int = ft_calloc(i, sizeof(int))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_int[i]);
		free(ptr_int);
	}
	write(1, "\n", 1);
	ft_putstr("   calloc(10, sizeof(size_t)) : ");
	i = 10;
	if ((ptr_size_t = calloc(i, sizeof(size_t))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_size_t[i]);
		free(ptr_size_t);
	}
	write(1, "\n", 1);
	ft_putstr("ft_calloc(10, sizeof(size_t)) : ");
	i = 10;
	if ((ptr_size_t = ft_calloc(i, sizeof(size_t))) != NULL)
	{
		while (i-- > 0)
			ft_putnbr(ptr_size_t[i]);
		free(ptr_size_t);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRDUP
	ft_putstr("\t\t\t\t\t\t\tFT_STRDUP\n");
//	str_13 = strdup(NULL);
//	str_13 = ft_strdup(NULL);
	ft_putstr("   strdup(\"\") : ");
	if ((str_13 = strdup("")) != NULL)
	{
		if (*str_13 == '\0')
			ft_putstr("\\0");
		free(str_13);
	}
	write(1, "\n", 1);
	ft_putstr("ft_strdup(\"\") : ");
	if ((str_13 = ft_strdup("")) != NULL)
	{
		if (*str_13 == '\0')
			ft_putstr("\\0");
		free(str_13);
	}
	write(1, "\n", 1);
	ft_putstr("   strdup(\"Hello \") : ");
	if ((str_13 = strdup("Hello ")) != NULL)
	{
		ft_putstr(str_13);
		free(str_13);
	}
	write(1, "\n", 1);
	ft_putstr("ft_strdup(\"Hello \") : ");
	if ((str_13 = ft_strdup("Hello ")) != NULL)
	{
		ft_putstr(str_13);
		free(str_13);
	}
	write(1, "\n", 1);
	ft_putstr("   strdup(\"world!\") : ");
	if ((str_13 = strdup("world!")) != NULL)
	{
		ft_putstr(str_13);
		free(str_13);
	}
	write(1, "\n", 1);
	ft_putstr("ft_strdup(\"world!\") : ");
	if ((str_13 = ft_strdup("world!")) != NULL)
	{
		ft_putstr(str_13);
		free(str_13);
	}
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_SUBSTR
	ft_putstr("\t\t\t\t\t\t\tFT_SUBSTR\n");
	src = "Hello!";
	ft_putstr("src = ");
	ft_putstr(src);
	write(1, "\n", 1);
	write(1, "\n", 1);
	ft_putstr("ft_substr(src, 0, 500000000000) [expected: Hello!] : ");
	ft_putstr(dest = ft_substr(src, 0, 500000000000));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_substr(src, 0, 0) [expected: \\0] : ");
	ft_putstr(dest = ft_substr(src, 0, 0));
	if (*dest == '\0')
		ft_putstr("\\0");
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_substr(src, 7, 3) [expected: \\0] : ");
	ft_putstr(dest = ft_substr(src, 7, 3));
	if (*dest == '\0')
		ft_putstr("\\0");
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_substr(src, 6, 3) [expected: \\0] : ");
	ft_putstr(dest = ft_substr(src, 6, 3));
	if (*dest == '\0')
		ft_putstr("\\0");
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_substr(src, 5, 3) [expected: !] : ");
	ft_putstr(dest = ft_substr(src, 5, 3));
	if (*dest == '\0')
		ft_putstr("\\0");
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_substr(NULL, 50, 0) [expected: \\0] : ");
//	ft_putstr(dest = ft_substr(NULL, 50, 1));
	ft_putstr(dest = ft_substr(NULL, 50, 0));
	if (*dest == '\0')
		ft_putstr("\\0");
	free(dest);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRJOIN
	ft_putstr("\t\t\t\t\t\t\tFT_STRJOIN\n");
	ft_putstr("ft_strjoin(\"\", \"\") [expected: \\0] : ");
	ft_putstr(dest = ft_strjoin("", ""));
	if (*dest == '\0')
		write(1, "\\0", 2);
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strjoin(\"\", \"world!\") [expected: world!] : ");
	ft_putstr(dest = ft_strjoin("", "world!"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strjoin(\"Hello\", \"\") [expected: Hello] : ");
	ft_putstr(dest = ft_strjoin("Hello", ""));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strjoin(\"Hello \", \"world!\") [expected: Hello world!] : ");
	ft_putstr(dest = ft_strjoin("Hello ", "world!"));
	free(dest);
	write(1, "\n", 1);
/*	ft_putstr("ft_strjoin(NULL, \"world!\") [expected: ] : ");
	ft_putstr(dest = ft_strjoin(NULL, "world!"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strjoin(NULL, NULL) [expected: ] : ");
	ft_putstr(dest = ft_strjoin(NULL, NULL));
	free(dest);
	write(1, "\n", 1);
*/
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRTRIM
	ft_putstr("\t\t\t\t\t\t\tFT_STRTRIM\n");
	ft_putstr("ft_strtrim(\"\\n \\t Hey! \\tHello\\tworld!   \\n\\t\", \" \\n\\t\") [expected: Hey \\tHello\\tworld!] : ");
	ft_putstr(dest = ft_strtrim( "\n \t Hey! \tHello\tworld! \n\t", " \n\t"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"Hello world!\", \"\") [expected: Hello world!] : ");
	ft_putstr(dest = ft_strtrim("Hello world!", ""));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"\", \"\\n\\t\") [expected: \\0] : ");
	ft_putstr(dest = ft_strtrim("", "\n\t"));
	if (*dest == '\0')
		write(1, "\\0", 2);
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"Hello world!\", \"elo wrd!?\") [expected: H] : ");
	ft_putstr(dest = ft_strtrim("Hello world!", "elo wrd!?"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"Hello world!\", \"Helo wrd!?\") [expected: \\0] : ");
	ft_putstr(dest = ft_strtrim("Hello world!", "Helo wrd!?"));
	if (*dest == '\0')
		write(1, "\\0", 2);
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"Hiiiiiii!\", \"i\") [expected: Hiiiiiii!] : ");
	ft_putstr(dest = ft_strtrim("Hiiiiiii!", "i"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"iiiiiii!\", \"i\") [expected: !] : ");
	ft_putstr(dest = ft_strtrim("iiiiiii!", "i"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(\"Hiiiiiii\", \"i\") [expected: H] : ");
	ft_putstr(dest = ft_strtrim("Hiiiiiii", "i"));
	free(dest);
	write(1, "\n", 1);
/*	ft_putstr("ft_strtrim(\"Hello world!\", NULL) : ");
	ft_putstr(dest = ft_strtrim("Hello world!", "NULL"));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strtrim(NULL, NULL) : ");
	ft_putstr(dest = ft_strtrim("NULL", "NULL"));
	free(dest);
	write(1, "\n", 1);
*/
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_SPLIT
	ft_putstr("\t\t\t\t\t\t\tFT_SPLIT\n");
//	if(!(array_14 = ft_split(NULL, ' ')))
//		return (-1);
	ft_putstr("ft_split(Hello world! Hallo Welt! Salut monde!, \' \' ) [expected: ... - (null)] : ");
	if (!(array_14 = ft_split("Hello world! Hallo Welt! Salut monde!", ' ')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(\"\", \' \' ) [expected: (null)] : ");
	if (!(array_14 = ft_split("", ' ')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(\"\", \'\\0\' ) [expected: (null)] : ");
	if (!(array_14 = ft_split("", '\0')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(abc abc abc, \'d\' ) [expected: abc abc abc - (null)] : ");
	if (!(array_14 = ft_split("abc abc abc", 'd')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(abc abc abc, \'\\0\' ) [expected: abc abc abc - (null)] : ");
	if (!(array_14 = ft_split("abc abc abc", '\0')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(abc abc abc, \'b\' ) [expected: a - c a - c a - c - (null)] : ");
	if (!(array_14 = ft_split("abc abc abc", 'b')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	ft_putstr("ft_split(aaaaaaa, \'a\' ) [expected: (null)] : ");
	if (!(array_14 = ft_split("aaaaaaa", 'a')))
	{
		ft_putstr("Error!");
		return (-1);
	}
	i = 0;
	while (array_14[i] != NULL)
	{
		ft_putstr(array_14[i]);
		if (*(array_14[i]) == '\0')
			write(1, "\\0", 2);
		free(array_14[i++]);
		write(1, " - ", 3);
	}
	write(1, "(null)", 6);
	free(array_14);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_ITOA
	ft_putstr("\t\t\t\t\t\t\tFT_ITOA\n");
	ft_putstr("ft_itoa(INT_MAX) [expected: 2147483647] : ");
	ft_putstr(number = ft_itoa(INT_MAX));
	free(number);
	write(1, "\n", 1);
	ft_putstr("ft_itoa(-0) [expected: 0] : ");
	ft_putstr(number = ft_itoa(-0));
	free(number);
	write(1, "\n", 1);
	ft_putstr("ft_itoa(-42) [expected: -42] : ");
	ft_putstr(number = ft_itoa(-42));
	free(number);
	write(1, "\n", 1);
	ft_putstr("ft_itoa(-+-42) [expected: 42] : ");
	ft_putstr(number = ft_itoa(-+-42));
	free(number);
	write(1, "\n", 1);
	ft_putstr("ft_itoa(INT_MAX) [expected: -2147483648] : ");
	ft_putstr(number = ft_itoa(INT_MIN));
	free(number);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_STRMAPI
	ft_putstr("\t\t\t\t\t\t\tFT_STRMAPI\n");
//	ft_putstr(dest = ft_strmapi(NULL, &ft_rot_i));
	ft_putstr("ft_strmapi(\"Hello world!\", &ft_rot_i) [expected: Hfnos cvzun!] : ");
	ft_putstr(dest = ft_strmapi("Hello world!", &ft_rot_i));
	free(dest);
	write(1, "\n", 1);
	ft_putstr("ft_strmapi(\"\", &ft_rot_i) [expected: \\0] : ");
	ft_putstr(dest = ft_strmapi("", &ft_rot_i));
	if (*dest == '\0')
		write(1, "\\0", 2);
	free(dest);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_PUTCHAR_FD
	ft_putstr("\t\t\t\t\t\t\tFT_PUTCHAR_FD\n");
	ft_putstr("ft_putchar_fd(':', 0) ('-', 1) (')', 2) ('!', 3) [expected: :-)] : ");
	ft_putchar_fd(':', 0);
	ft_putchar_fd('-', 1);
	ft_putchar_fd(')', 2);
	ft_putchar_fd('!', 3);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_PUTSTR_FD
	ft_putstr("\t\t\t\t\t\t\tFT_PUTSTR_FD\n");
	ft_putstr("ft_putstr_fd(\":-)\", 1) [expected: :-)] : ");
	ft_putstr_fd(":-)", 1);
	write(1, "\n", 1);
	ft_putstr("ft_putstr_fd(\":-)\", 3) [expected: ] : ");
	ft_putstr_fd(":)", 3);
	write(1, "\n", 1);
	ft_putstr("ft_putstr_fd(\"\", 1) [expected: ] : ");
	ft_putstr_fd("", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_PUTENDL_FD
	ft_putstr("\t\t\t\t\t\t\tFT_PUTENDL_FD\n");
	ft_putstr("ft_putendl_fd(\":-)\", 1) [expected: :-)] : ");
	ft_putendl_fd(":-)", 1);
	ft_putstr("ft_putendl_fd(\":-)\", 3) [expected: ] : ");
	ft_putendl_fd(":-)", 3);
	write(1, "\n", 1);
	ft_putstr("ft_putendl_fd(\"\", 1) [expected: ] : ");
	ft_putendl_fd("", 1);
	write(1, "\n", 1);
	write(1, "\n", 1);



//									FT_PUTNBR_FD
	ft_putstr("\t\t\t\t\t\t\tFT_PUTNBR_FD\n");
	ft_putstr("ft_putnbr_fd(INT_MAX, 1) [expected: 2147483647] : ");
	ft_putnbr_fd(INT_MAX, 1);
	write(1, "\n", 1);
	ft_putstr("ft_putnbr_fd(-0, 1) [expected: 0] : ");
	ft_putnbr_fd(-0, 1);
	write(1, "\n", 1);
	ft_putstr("ft_putnbr_fd(-4, 1) [expected: -4] : ");
	ft_putnbr_fd(-4, 1);
	write(1, "\n", 1);
	ft_putstr("ft_putnbr_fd(-42, 3) [expected: ] : ");
	ft_putnbr_fd(-42, 3);
	write(1, "\n", 1);
	ft_putstr("ft_putnbr_fd(INT_MIN, 1) [expected: -2147483648]: ");
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);



	return (0);
}
