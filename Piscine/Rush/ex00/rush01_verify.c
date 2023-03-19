/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_verify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:31:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/19 21:31:43 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_column_t0(int board[4][4], char **tab)
{
	int	column;
	int	count;
	int	i;

	column = -1;
	while (++column < 4)
	{
		i = -1;
		count = 1;
		while (++i < 4)
		{
			if (board[i][column] == 4)
				break ;
			if (board[i][column] < board[i + 1][column])
				count++;
		}
		if (tab[0][column] != count + '0')
			return (0);
	}
	return (1);
}

int	ft_verify_column_t1(int board[4][4], char **tab)
{
	int	column;
	int	count;
	int	i;

	column = 4;
	while (--column >= 0)
	{
		i = 4;
		count = 1;
		while (--i >= 0)
		{
			if (board[i][column] == 4)
				break ;
			if (board[i][column] < board[i - 1][column])
				count++;
		}
		if (tab[1][column] != count + '0')
			return (0);
	}
	return (1);
}

int	ft_verify_row_t3(int board[4][4], char **tab)
{
	int	row;
	int	count;
	int	i;

	row = 4;
	while (--row >= 0)
	{
		i = 4;
		count = 1;
		while (--i >= 0)
		{
			if (board[row][i] == 4)
				break ;
			if (board[row][i] < board[row][i - 1])
				count++;
		}
		if (tab[3][row] != count + '0')
			return (0);
	}
	return (1);
}

int	ft_verify_row_t2(int board[4][4], char **tab)
{
	int	row;
	int	count;
	int	i;

	row = -1;
	while (++row < 4)
	{
		i = -1;
		count = 1;
		while (++i < 4)
		{
			if (board[row][i] == 4)
				break ;
			if (board[row][i] < board[row][i + 1])
				count++;
		}
		if (tab[2][row] != count + '0')
			return (0);
	}
	return (1);
}

