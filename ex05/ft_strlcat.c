/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:39:32 by dukim             #+#    #+#             */
/*   Updated: 2024/01/25 21:10:41 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	dest = dest + i;
	while (*src != '\0' && j + i + 1 < size)
	{
		*dest++ = *src++;
		j++;
	}
	while (*src++ != '\0')
		j++;
	*dest = '\0';
	if (i > size)
		return (j + size);
	return (i + j);
}
