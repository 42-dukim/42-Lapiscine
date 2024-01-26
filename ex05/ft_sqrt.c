/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:09:43 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 17:17:00 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(20));
	printf("%d\n", ft_sqrt(-4));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(308025));
	printf("%d\n", ft_sqrt(-1));
	printf("%d\n", ft_sqrt(0));
}*/
