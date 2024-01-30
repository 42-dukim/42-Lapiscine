/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:31:46 by dukim             #+#    #+#             */
/*   Updated: 2024/01/30 21:49:00 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	len = max - min;
	if (len <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * len);
	if (!*range)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (len);
}
/*
#include <stdio.h>

int	main()
{
	int max = 15, min = 1;
	int *arr;
	int size = ft_ultimate_range(&arr, min, max);

	if (!arr)
		printf("is Null!\n");

	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}*/
