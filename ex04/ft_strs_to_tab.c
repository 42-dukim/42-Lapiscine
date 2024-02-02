/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:38:04 by dukim             #+#    #+#             */
/*   Updated: 2024/02/02 18:53:59 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	str_cpy(char *dest, char *src)
{
	int	i;
	int	src_len;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	stock;
	int					i;

	stock = (struct s_stock_str *)(sizeof(struct s_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	i = 0;
	while (i < ac)
	{
		size = str_len(av[i]);
		stock[i]->str = av[i];
		stock[i]->copy = (char *)malloc(sizeof(char *) * (size + 1));
		str_cpy(stroc[i]->copy, av[i]);
		i++;
	}
	stock[i]->size = 0;
	stock[i]->str = 0;
	stock[i]->copy = 0;
	return (stock);
}
