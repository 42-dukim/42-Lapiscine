/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:43:14 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 17:57:14 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= get_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!is_prime(nb))
		nb++;
	return (nb);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_find_next_prime(5555));
}*/
