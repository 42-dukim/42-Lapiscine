/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:03:49 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 13:43:35 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	is_pass_ch(char ch)
{
	if ((9 <= ch && ch <= 13) || ch == ' ' \
			|| ch == '+' || ch == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sum;
	int	minus_cnt;
	int	state;

	sum = 0;
	minus_cnt = 0;
	state = 0;
	while (*str != '\0' && (is_number(*str) || is_pass_ch(*str)))
	{
		if (is_number(*str))
		{
			sum = sum * 10 + (*str - '0');
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
/*
#include <stdio.h>

int main()
{
	int num = ft_atoi("-1234");
	printf("%d\n", num);
	printf("%d\n", ft_atoi("   ---+--+1234ab567"));
	printf("%d\n", ft_atoi("-0-1234"));
	printf("%d\n", ft_atoi("-2147 483648"));
	printf("%d\n", ft_atoi("2147-483647"));
	printf("%d\n", ft_atoi("---10\n00"));
	printf("%d\n", ft_atoi("aa12bbf44"));
	printf("%d\n", ft_atoi("123213213--++122"));
}*/
