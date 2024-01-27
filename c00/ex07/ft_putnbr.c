/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:22:31 by dukim             #+#    #+#             */
/*   Updated: 2024/01/21 02:02:40 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pow_10(int nb)
{
	int	pow;

	if (nb >= 1000000000)
		return (1000000000);
	pow = 1;
	while (pow <= nb)
		pow *= 10;
	return (pow / 10);
}

void	ft_putnbr(int nb)
{
	char	str[11];
	int		pow;
	int		idx;

	idx = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		str[idx++] = '-';
	}
	pow = pow_10(nb);
	while (pow)
	{
		str[idx++] = (nb / pow) + '0';
		nb = nb % pow;
		pow /= 10;
	}
	if (idx)
		write(1, str, idx);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		write(1, "0", 1);
}
/*
int	main()
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(10000000000);
}*/
