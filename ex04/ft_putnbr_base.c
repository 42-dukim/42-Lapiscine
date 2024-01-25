/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:08:47 by dukim             #+#    #+#             */
/*   Updated: 2024/01/21 16:11:37 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	reverse_str(char *str, int size)
{
	int		start;
	char	temp;

	start = 0;
	while (start < size - 1)
	{
		temp = str[start];
		str[start] = str[size - 1];
		str[size - 1] = temp;
		start++;
		size--;
	}
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

void	ft_putnbr_base(int nbr, char *base)
{
	char			str[32];
	int				base_len;
	int				i;
	unsigned int	un_nbr;

	base_len = str_len(base);
	i = 0;
	if (!is_valid_base(base, base_len))
		return ;
	if (nbr < 0)
	{
		un_nbr = -(unsigned int)nbr;
		write(1, "-", 1);
	}
	else
		un_nbr = nbr;
	while (un_nbr)
	{
		str[i] = base[un_nbr % base_len];
		un_nbr = un_nbr / base_len;
		i++;
	}
	reverse_str(str, i);
	write(1, str, i);
}
/*
int main()
{
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	ft_putnbr_base(2147483648, "0123456789ABCDEF");
	ft_putnbr_base(-2147483648, "01");
	ft_putnbr_base(-2147483648, "poneyvif");
}*/
