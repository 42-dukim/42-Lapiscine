/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:34:31 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 13:51:15 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_pass_ch(char ch)
{
	if ((9 <= ch && ch <= 13) || ch == ' ' \
			|| ch == '+' || ch == '-')
		return (1);
	return (0);
}

int	get_base_idx(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base, int base_len)
{
	int	minus_cnt;
	int	state;
	int	sum;

	sum = 0;
	minus_cnt = 0;
	state = 0;
	while (*str != '\0' && (get_base_idx(*str, base) >= 0 || is_pass_ch(*str)))
	{
		if (get_base_idx(*str, base) >= 0)
		{
			sum = sum * base_len + get_base_idx(*str, base);
			state++;
		}
		else if (state)
			break ;
		else if (*str == '-')
			minus_cnt++;
		str++;
	}
	if (minus_cnt % 2)
		sum = -sum;
	return (sum);
}

int	is_valid_base(char *base, char base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len <= 1)
		return (0);
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;

	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (!is_valid_base(base, base_len))
		return (0);
	return (atoi_base(str, base, base_len));
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi_base("---gC351", "g123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("10000", "01"));
	printf("%d\n", ft_atoi_base("12557", "01234567"));
	printf("%d\n", ft_atoi_base("    0-12557", "01234567"));
	//ft_putnbr_base("2147483648", "0123456789ABCDEF");
	//ft_putnbr_base(-2147483648, "poneyvif");
}*/
