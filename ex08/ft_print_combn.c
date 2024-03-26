/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:06:29 by dukim             #+#    #+#             */
/*   Updated: 2024/01/14 22:50:15 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	combn_print(char number[10], int length)
{	
	int	cnt;

	cnt = 0;
	while (cnt < length)
	{
		write(1, &number[cnt++], 1);
	}
	if (number[0] != (10 - length) + '0')
		write(1, ", ", 2);
}

void	combn(char number[10], int n)
{	
	int	num;
	int	digits;

	num = n - 1;
	digits = 1;
	while (number[num] == (10 - digits) + '0')
	{
		num--;
		digits++;
	}
	number[num] = number[num] + 1;
	num++;
	while (num < n)
	{
		number[num] = number[num - 1] + 1;
		num++;
	}
}

void	init_number(char number[10], int n)
{
	int	start;

	start = 0;
	while (start < n)
	{
		number[start] = start + '0';
		start++;
	}
}

void	ft_print_combn(int n)
{
	char	number[10];

	init_number(number, n);
	while (1)
	{
		combn_print(number, n);
		combn(number, n);
		if (number[0] == (10 - n) + '0')
		{
			combn_print(number, n);
			return ;
		}
	}
}
