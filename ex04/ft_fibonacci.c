/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:56:00 by dukim             #+#    #+#             */
/*   Updated: 2024/01/26 14:09:21 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>

int	main(){
	printf("%d -> %d\n", 5, ft_fibonacci(5)); 
	printf("%d -> %d\n", 0, ft_fibonacci(0)); 
	printf("%d -> %d\n", 16, ft_fibonacci(16)); 
	printf("%d -> %d\n", 10, ft_fibonacci(10)); 
	printf("%d -> %d\n", -10, ft_fibonacci(-10)); 
}*/
