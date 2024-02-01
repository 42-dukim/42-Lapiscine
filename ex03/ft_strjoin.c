/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:55:28 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 02:01:00 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_total_len(char **strs, int size, int sep_len)
{
	int	total_len;
	int	i;
	int	j;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		i++;
		total_len += j;
		if (i != size - 1)
			total_len += sep_len;
	}
	return (total_len);
}

int	str_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

int	change_size(int size, char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	if (i < size)
		size = i;
	return (size);
}

void	join_str(int size, char **strs, char *sep, char *str_join)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		i += str_copy(&str_join[i], strs[j]);
		if (j != size - 1)
			i += str_copy(&str_join[i], sep);
		j++;
	}
	str_join[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_join;
	int		total_len;
	int		sep_len;

	if (size == 0)
	{
		str_join = (char *)malloc(sizeof(char) * 1);
		str_join[0] = '\0';
		return (str_join);
	}
	size = change_size(size, strs);
	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	total_len = get_total_len(strs, size, sep_len);
	str_join = (char *)malloc(sizeof(char *) * (total_len + 1));
	if (!str_join)
		return (0);
	join_str(size, strs, sep, str_join);
	return (str_join);
}
/*
#include <stdio.h>

int main()
{
	char *str[10] = {"sdfsdf", "2", "3", "4", 0};
	char *sep = ", ";

	char *join = ft_strjoin(1000, str, sep);
	printf("%s\n", join);
}*/
