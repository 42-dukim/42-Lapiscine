/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:17:20 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 17:56:20 by dukim            ###   ########.fr       */
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

int	ft_is_prime(int nb)
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
/*
#include <stdio.h>

int	main()
{
	
	for(int i = 1; i < 100; i++)
		if (ft_is_prime(i))
			printf("%d ", i);
}*/
