/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:13 by dukim             #+#    #+#             */
/*   Updated: 2024/01/25 20:10:45 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char *str1 = "1234";
	char *str2 = "12345";
	char *str3 = "abcdefg";
	char *str4 = "ABCDEFG";
	char *str5 = "";
	char *str6 = "h";
	char *str7 = "!@#$%";
	char *str8 = "!@#$%";

	printf("%s <-> %s: %d\n", str1, str2, ft_strcmp(str1, str2)); 
	printf("%s <-> %s: %d\n", str3, str4, ft_strcmp(str3, str4)); 
	printf("%s <-> %s: %d\n", str5, str6, ft_strcmp(str5, str6)); 
	printf("%s <-> %s: %d\n", str7, str8, ft_strcmp(str7, str8)); 
}*/
