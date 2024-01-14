/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 03:30:27 by dukim             #+#    #+#             */
/*   Updated: 2024/01/14 04:48:41 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb2_print(int num1, int num2)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = num1 / 10 + '0';
	b = num1 % 10 + '0';
	c = num2 / 10 + '0';
	d = num2 % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (num1 != 98 || num2 != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			comb2_print(num1, num2);
			num2++;
		}
		num2 = ++num1 + 1;
	}
}
