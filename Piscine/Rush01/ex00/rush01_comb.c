/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:34:23 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/19 21:34:23 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_column_t0(int board[4][4], char **tab);
int	ft_verify_column_t1(int board[4][4], char **tab);
int	ft_verify_row_t2(int board[4][4], char **tab);
int	ft_verify_row_t3(int board[4][4], char **tab);
void	ft_print_table(int board[4][4]);

int is_valid(int matrix[4][4], int row, int col, int num) 
{
	int i;
		
	i = -1;
    // Verifica linha
    while (++i < 4) 
	{
        if (matrix[row][i] == num) 
		{
            return (0);
        }
    }
	i = -1;
    // Verifica coluna
    while (++i < 4) 
	{
        if (matrix[i][col] == num) 
		{
            return (0);
        }
    }
    return (1);
}

void ft_combinations(int matrix[4][4], int row, int col, char **tab, int *ptr) 
{
	int num;
    if (row == 4) 
	{
	    if (ft_verify_row_t3(matrix, tab) == 1)
			if (ft_verify_column_t0(matrix, tab) == 1) 
				if (ft_verify_column_t1(matrix, tab) == 1)
				{
					ft_print_table(matrix);
					*ptr = 1;
				}	
	}			
					
    if (col == 4)
	{
		ft_combinations(matrix, row + 1, 0, tab, ptr);
        return;
    }
	
	num = 0;
    // Tenta os numeros de 1 a 4 na celula
    while (++num <= 4) 
	{
        if (is_valid(matrix, row, col, num)) 
		{
            matrix[row][col] = num;
            ft_combinations(matrix, row, col + 1, tab, ptr);
            matrix[row][col] = 0;
        }
    }
}
