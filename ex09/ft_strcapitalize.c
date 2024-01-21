/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:49:59 by dukim             #+#    #+#             */
/*   Updated: 2024/01/21 15:16:49 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char ch)
{
	if ((int)ch < 65 || (int)ch > 90)
		return (0);
	return (1);
}

int	is_lowercase(char ch)
{
	if ((int)ch < 97 || (int)ch > 122)
		return (0);
	return (1);
}

int	is_numeric(char ch)
{
	if ((int)ch < 48 || (int)ch > 57)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (is_lowercase(str[0]))
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (!is_uppercase(str[i - 1]) && !is_lowercase(str[i - 1]) \
				&& !is_numeric(str[i - 1]) && is_lowercase(str[i]))
			str[i] -= 32;
		else if ((is_lowercase(str[i - 1]) || is_uppercase(str[i - 1])) \
				|| is_numeric(str[i - 1]) && is_uppercase(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
