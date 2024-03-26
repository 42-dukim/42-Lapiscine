/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:13:07 by dukim             #+#    #+#             */
/*   Updated: 2024/01/30 21:15:46 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	len;

	i = argc - 1;
	while (i > 0)
	{
		len = 0;
		while (argv[i][len] != '\0')
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
