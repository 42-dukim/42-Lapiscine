/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:57:44 by dukim             #+#    #+#             */
/*   Updated: 2024/01/30 21:01:31 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct position
{
	int	row;
	int	col;
}		t_position;

const t_position	g_move[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, \
									{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
static int			g_map[10][10];

int	is_valid_position(t_position pos)
{
	if ((0 <= pos.row && pos.row <= 9) \
		&& (0 <= pos.col && pos.col <= 9))
		return (1);
	return (0);
}

int	check_able_position(t_position pos)
{
	int			i;
	t_position	origin;

	i = 0;
	origin = pos;
	while (i < 8)
	{
		while (is_valid_position(pos))
		{	
			if (g_map[pos.row][pos.col] == 1)
				return (0);
			pos.row += g_move[i].row;
			pos.col += g_move[i].col;
		}
		i++;
		pos = origin;
	}
	return (1);
}

void	print_queen_array(int *queen_array)
{
	int		i;
	char	queen;

	i = 0;
	while (i < 10)
	{
		queen = queen_array[i] + '0';
		write(1, &queen, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	solved_puzzle(t_position pos, int *queen_array, int queen, int *cnt)
{
	if (queen == 10)
	{
		print_queen_array(queen_array);
		(*cnt)++;
		return (0);
	}
	pos.row = 0;
	while (is_valid_position(pos))
	{
		if (check_able_position(pos))
		{
			g_map[pos.row][pos.col] = 1;
			queen_array[queen] = pos.row;
			pos.col += 1;
			if (solved_puzzle(pos, queen_array, queen + 1, cnt))
				return (1);
			else
			{
				pos.col -= 1;
				g_map[pos.row][pos.col] = 0;
			}
		}
		pos.row += 1;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int			cnt;
	t_position	start;
	int			queen_array[10];

	cnt = 0;
	start.row = 0;
	start.col = 0;
	solved_puzzle(start, queen_array, 0, &cnt);
	return (cnt);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_ten_queens_puzzle());
}*/
