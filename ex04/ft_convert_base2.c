/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 03:15:40 by dukim             #+#    #+#             */
/*   Updated: 2024/01/31 03:55:23 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base, char base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len <= 1)
		return (0);
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_space_ch(char ch)
{
	if ((9 <= ch && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

int	get_base_idx(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_base_len(long long nbr, int base_len)
{
	int	len;

	len = 1;
	while (1)
	{
		nbr /= base_len;
		if (!nbr)
			break ;
		len++;
	}
	return (len);
}
