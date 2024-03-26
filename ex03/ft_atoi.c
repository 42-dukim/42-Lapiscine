/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:03:49 by dukim             #+#    #+#             */
/*   Updated: 2024/01/31 01:16:06 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	is_space_ch(char ch)
{
	if ((9 <= ch && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

int	is_sign_ch(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sum;
	int	minus_cnt;

	sum = 0;
	minus_cnt = 0;
	while (is_space_ch(*str))
		str++;
	while (is_sign_ch(*str))
	{
		if (*str == '-')
			minus_cnt++;
		str++;
	}
	while (*str != '\0' && is_number(*str))
	{
		sum = sum * 10 + (*str - '0');
		str++;
	}
	if (minus_cnt % 2)
		sum = -sum;
	return (sum);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%d\n", ft_atoi("   ---+--+1234ab567"));
	printf("%d\n", ft_atoi("-0-1234"));
	printf("%d\n", ft_atoi("-2147 483648"));
	printf("%d\n", ft_atoi("2147-483647"));
	printf("%d\n", ft_atoi("--  -\t1000"));
	printf("%d\n", ft_atoi("  aa12bbf44"));
	printf("%d\n", ft_atoi("123213213--++122"));
	printf("%d\n", ft_atoi("2147483648"));
	printf("%d\n", ft_atoi("\t\t+-123"));
	printf("\n");
	printf("%d\n", atoi("   ---+--+1234ab567"));
	printf("%d\n", atoi("-0-1234"));
	printf("%d\n", atoi("-2147 483648"));
	printf("%d\n", atoi("2147-483647"));
	printf("%d\n", atoi("--  -\t1000"));
	printf("%d\n", atoi("aa12bbf44"));
	printf("%d\n", atoi("123213213--++122"));
	printf("%d\n", atoi("2147483648"));
	printf("%d\n", atoi("-123456789123456789"));
}*/
