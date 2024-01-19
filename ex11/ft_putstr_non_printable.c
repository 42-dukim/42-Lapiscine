/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:51:38 by dukim             #+#    #+#             */
/*   Updated: 2024/01/19 19:40:56 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_non_printable(char ch)
{
	if ((int)ch <= 31 || (int)ch == 127)
		return (1);
	return (0);
}

char	*trs_hex(char *c, char dec)
{
	c[0] = '\\';
	c[1] = (int)dec / 16 + '0';
	if ((int)dec < 10)
		c[2] = (int)dec + '0';
	else
	{
		c[2] = 'a' + ((int)dec - 10);
	}
	return (c);
}

void	ft_putstr_non_printable(char *str)
{
	char	c[3];

	while (*str != '\0')
	{
		if (is_non_printable(*str))
		{
			trs_hex(c, *str);
			write(1, c, 3);
		}
		else
			write(1, str, 1);
		str++;
	}
}
