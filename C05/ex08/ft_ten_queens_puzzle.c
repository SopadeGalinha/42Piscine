/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jhogonca@student.42porto.com <jhogonca    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:24:41 by  jhogonca@s       #+#    #+#             */
/*   Updated: 2023/03/30 18:18:53 by  jhogonca@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

int	check_board(int board[10][10], int row, int column)
{
	int	i;
	int	j;
	int	d;

	i = -1;
	j = -1;
	d = 0;
	while (column >= 0)
	{
		if (row + d >= 0 && row + d <= 9)
			if (board[row + d][column] != 0)
				return (0);
		if (row - d >= 0 && row - d <= 9)
			if (board[row - d][column] != 0)
				return (0);
		if (board[row][column] != 0)
			return (0);
		d++;
		column--;
	}
	return (1);
}

void	print_solution(int board[][10], char str[2])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
	{
	j = -1;
		while (++j < 10)
		{
			if (board[j][i] == 1)
			{
				str[0] = j + '0';
				write(1, "\033[32m", 5);
				write(1, str, 1);
				write(1, "\033[0m", 4);
				break ;
			}
		}
	}
}

int	ft_ten_queens_puzzle_aux(int board[10][10], int col)
{
	int		i;
	int		count;
	char	str[2];
	int		j;

	count = 0;
	if (col == 10)
	{
		i = -1;
		print_solution(board, str);
		write(1, "\n", 1);
		return (1);
	}
	i = -1;
	while (++i < 10)
	{
		if (check_board(board, i, col))
		{
			board[i][col] = 1;
			count += ft_ten_queens_puzzle_aux(board, col + 1);
			board[i][col] = 0;
		}
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	j;
	int	board[10][10];

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			board[i][j] = 0;
	}
	return (ft_ten_queens_puzzle_aux(board, 0));
}
