/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:28:47 by anhigo-s          #+#    #+#             */
/*   Updated: 2021/09/11 21:37:58 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hex_len(size_t n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 16;
		++count;
	}
	return (count);
}

static int	print_hex(char *str, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
	{
		while (str[i] != '\0')
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	i = putstring_fd(str, 1);
	return (i);
}

int	hex_str(size_t n, char c)
{
	char			*str;
	char			*digits;
	unsigned int	i;

	i = hex_len(n);
	digits = "0123456789abcdef";
	str = malloc(i * sizeof(char));
	if (!str)
		return (0);
	while (i)
	{
		str[--i] = digits[n % 16];
		n = n / 16;
	}
	i = print_hex(str, c);
	free(str);
	return (i);
}

int	hex_void(size_t n)
{
	int	i;

	i = 0;
	i += putstring_fd("0x", 1);
	i += hex_str(n, 'x');
	return (i);
}