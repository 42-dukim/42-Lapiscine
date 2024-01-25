/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:51:38 by dukim             #+#    #+#             */
/*   Updated: 2024/01/25 22:30:40 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_non_printable(char ch)
{
	if ((int)ch <= 31 || (int)ch == 127)
		return (1);
	return (0);
}

char	*trs_hex(char *c, unsigned char dec, char *hex_str)
{
	int		i;
	int		hex;

	i = 2;
	c[0] = '\\';
	c[1] = '0';
	hex = dec;
	while (hex)
	{
		c[i] = hex_str[hex % 16];
		hex = hex / 16;
		i--;
	}
	return (c);
}

void	ft_putstr_non_printable(char *str)
{
	char	c[3];
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_non_printable(str[i]))
		{
			trs_hex(c, (unsigned char)str[i], "0123456789abcdef");
			write(1, c, 3);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
int main()
{
	char c[3];
	unsigned char t = 200;
	//printf("%s\n", trs_hex(c, 128));
	
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}*/
