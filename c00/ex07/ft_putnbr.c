/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:27:26 by dukim             #+#    #+#             */
/*   Updated: 2024/01/15 02:40:30 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putbr_print(char ch[11], int length)
{
	if (length == -1)
		write(1, "0", 1);
	while (length > -1)
	{
		write(1, &ch[length--], 1);
	}
}

void	ft_putnbr(int nb)
{	
	char	temp[11];
	int		r_cnt;

	r_cnt = 0;
	if (nb == 0)
		temp[0] = 0;
	if (nb == -2147483648)
	{
		putbr_print("8463847412-", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (nb)
	{
		temp[r_cnt++] = nb % 10 + '0';
		nb = nb / 10;
	}
	putbr_print(temp, r_cnt - 1);
}
