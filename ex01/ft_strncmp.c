/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:55:46 by dukim             #+#    #+#             */
/*   Updated: 2024/01/25 20:32:50 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	if (i == n)
		return (0);
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char *str1 = "1234";
	char *str2 = "123456";
	char *str3 = "abcdefg";
	char *str4 = "abcdufg";
	char *str5 = " ";
	char *str6 = "   ";
	char *str7 = "!@#$%";
	char *str8 = "!@#$%";

	printf("%s <-> %s: %d\n", str1, str2, ft_strncmp(str1, str2, 3));
	printf("%s <-> %s: %d\n", str3, str4, ft_strncmp(str3, str4, 7));
	printf("%s <-> %s: %d\n", str5, str6, ft_strncmp(str5, str6, 2));
	printf("%s <-> %s: %d\n", str7, str8, ft_strncmp(str7, str8, 3));
	printf("%s <-> %s: %d\n", str3, str4, ft_strncmp(str3, str4, 0));
	
	printf("\n");

	printf("%s <-> %s: %d\n", str1, str2, strncmp(str1, str2, 6));
	printf("%s <-> %s: %d\n", str5, str6, strncmp(str5, str6, 3));
	printf("%s <-> %s: %d\n", str3, str4, strncmp(str3, str4, 0));
}*/
