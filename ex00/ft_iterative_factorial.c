/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:27:19 by dukim             #+#    #+#             */
/*   Updated: 2024/01/30 19:16:41 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	factorial;

	if (nb < 0)
		return (0);
	i = 1;
	factorial = 1;
	while (i <= nb)
		factorial *= i++;
	return (factorial);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_iterative_factorial(10));
}*/
