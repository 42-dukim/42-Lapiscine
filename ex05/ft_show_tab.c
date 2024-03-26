/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:39 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 20:31:14 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

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

void	put_nbr(int nb)
{
	char	str[11];
	int		pow;
	int		idx;

	idx = 0;
	pow = pow_10(nb);
	while (pow)
	{
		str[idx++] = (nb / pow) + '0';
		nb = nb % pow;
		pow /= 10;
	}
	str[idx] = '\0';
	if (idx)
		put_str(str);
	else
		put_str("0");
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while ((par[i].str))
	{
		put_str(par[i].str);
		put_nbr(par[i].size);
		put_str(par[i].copy);
		i++;
	}
}
