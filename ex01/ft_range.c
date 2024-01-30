/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:35:11 by dukim             #+#    #+#             */
/*   Updated: 2024/01/28 03:00:23 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	len;
	int	i;

	len = max - min;
	if (len <= 0)
		return (0);
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{	
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	int *arr;
	arr = ft_range(9, 10);
	if (arr)
		for(int i = 0; i < 10 - 9; i++)
			printf("%d ", arr[i]);
	else
		printf("is Null!\n");
}*/
