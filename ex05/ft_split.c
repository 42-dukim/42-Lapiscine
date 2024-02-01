/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:04:22 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 01:44:38 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_in_charset(char *charset, char ch)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	while (is_in_charset(charset, str[i]) && str[i])
		i++;
	cnt = 0;
	while (str[i])
	{
		while (!is_in_charset(charset, str[i]) && str[i])
			i++;
		while (is_in_charset(charset, str[i]) && str[i])
			i++;
		cnt++;
	}
	return (cnt);
}

char	*make_str(char *str, char *charset, int *index)
{
	char	*split;
	int		len;
	int		i;

	len = 0;
	while (!is_in_charset(charset, str[len]) && str[len])
		len++;
	split = (char *)malloc(sizeof(char) * (len + 1));
	if (!split)
		return (0);
	i = 0;
	while (i < len)
	{
		split[i] = str[i];
		i++;
	}
	*index += i;
	split[i] = '\0';
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_split;
	int		word_cnt;
	int		i;
	int		j;

	word_cnt = word_count(str, charset);
	str_split = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!str_split)
		return (0);
	i = 0;
	while (is_in_charset(charset, str[i]) && str[i])
		i++;
	j = 0;
	while (j < word_cnt)
	{
		str_split[j] = make_str(&str[i], charset, &i);
		while (is_in_charset(charset, str[i]) && str[i])
			i++;
		j++;
	}
	str_split[word_cnt] = 0;
	return (str_split);
}

/*
#include <stdio.h>

int main()
{
    char *str = "abc-fsdf^^-^    d\t\t e121\n23213\t\t\t   \t\t";
    char *charset = "\t ";
    char **split = ft_split(str, charset);
	
	printf("split: %p\n", split);

    for (int i = 0; i < word_count(str, charset) + 1; i++)
        printf("%s\n", split[i]);
}*/
