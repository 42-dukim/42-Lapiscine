/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:11:29 by dukim             #+#    #+#             */
/*   Updated: 2024/01/27 16:22:44 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_str(char *str_slice, char *to_find)
{
	int	i;

	i = 0;
	while (str_slice[i] != '\0' && to_find[i] != '\0')
	{
		if (str_slice[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_in_str(&str[i], to_find))
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char *to_find = "1";
	char *str = "123 456";
	char *ptr = ft_strstr(str, to_find);

	if (ptr != NULL)
		printf("%s\n", ptr);
	else
		printf("is Null!\n");

	ptr = strstr(str, to_find);
	if (ptr != NULL)
		printf("%s\n", ptr);
	else
		printf("is Null!\n");
}*/
