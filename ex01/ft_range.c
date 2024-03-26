/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:35:11 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 15:24:53 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	i = 0;
	while (min < max)
	{	
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	int *arr;
	arr = ft_range(-10, 11);
	if (arr)
		for(int i = 0; i < (11 - -10); i++)
			printf("%d ", arr[i]);
	else
		printf("is Null!\n");
}*/
