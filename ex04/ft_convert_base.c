/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:28:39 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 20:02:54 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid_base(char *base, char base_len);
int		is_space_ch(char ch);
int		get_base_idx(char ch, char *base);
int		get_str_len(char *str);
int		get_base_len(long long nbr, int base_len);

int	atoi_base(char *str, char *base, int base_len)
{
	int	minus_cnt;
	int	sum;

	sum = 0;
	minus_cnt = 0;
	while (is_space_ch(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_cnt++;
		str++;
	}
	while (*str != '\0' && get_base_idx(*str, base) >= 0)
	{
		sum = sum * base_len + get_base_idx(*str, base);
		str++;
	}
	if (minus_cnt % 2)
		sum = -sum;
	return (sum);
}

char	*putnbr_base(long long nbr, char *base, int base_len)
{
	char	*str;
	int		len;
	int		i;

	len = get_base_len(nbr, base_len);
	if (nbr < 0)
	{
		str = (char *)malloc(sizeof(char) * (++len + 1));
		str[0] = '-';
		nbr = -nbr;
	}
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	i = 1;
	while (1)
	{
		str[len - i++] = base[nbr % base_len];
		nbr = nbr / base_len;
		if (!nbr)
			break ;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	base_from_len;
	int	base_to_len;

	base_from_len = get_str_len(base_from);
	base_to_len = get_str_len(base_to);
	if (!is_valid_base(base_from, base_from_len) \
			|| !is_valid_base(base_to, base_to_len))
		return (0);
	return (putnbr_base(atoi_base(nbr, base_from, base_from_len), \
									base_to, base_to_len));
}

#include <stdio.h>

int	main()
{
	printf("%s\n", ft_convert_base("   \n\n--12345", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("   \n\n--12345", " \t0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("   \n\n--12345", "0123456789abcdef", "\t01"));
	printf("%s\n", ft_convert_base("   \n\n--12345", "-0123456789abcdef", "\t01"));
	printf("%s\n", ft_convert_base("", "0123456789abcdef", "0123456789"));
	printf("%s\n", ft_convert_base("2147483649", "0123456789", "0123456789"));
}
