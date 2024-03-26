/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:40:38 by dukim             #+#    #+#             */
/*   Updated: 2024/01/15 00:53:57 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;

	start = 0;
	while (start <= size - 1)
	{
		temp = tab[start];
		tab[start] = tab[size - 1];
		tab[size - 1] = temp;
		start++;
		size--;
	}
}
