/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:57:58 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/18 03:57:58 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_table(int row[][4])
{
	int	i;
	int	c;

	i = -1;
	i = -1;
	while (++i < 4)
	{
		c = -1;
		while (++c < 4)
		{
			ft_putchar(row[i][c] + '0');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	while(src[++i] && n > 0)
	{
		if (src[i] == ' ')
			continue ;
		dest[++c] = src[i];
		n--;
	}
	dest[c + 1] = '\0';
	return (dest);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (result * sign);
}

// retorna falso se encontrar o valor 
int	ft_verify_cell(int tab[][4], int line, int column, int value)
{
	int temp;

	temp = -1;
	while(++temp < 4) // verificar linha
		if(tab[temp][column] == value)
			return (0);
	temp = -1;
	while (++temp < 4) // verifica coluna
		if (tab[line][temp] == value)
			return (0);
	return (1);
}

void	ft_check_four_vertical(int board[][4], char **tab)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		if (tab[0][i] == '4')
		{
			j = -1;
			while (++j < 4)
				board[j][i] = j + 1;
		}
		if (tab[1][i] == '4')
		{
			j = 4;
			k = 0;
			while (--j >= 0)
				board[j][i] = ++k;
		}
	}

}

void	ft_check_four_horizontal(int board[][4], char **tab)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		if (tab[2][i] == '4')
		{
			j = -1;
			while (++j < 4)
				board[i][j] = j + 1;
		}
		if (tab[3][i] == '4')
		{
			j = 4;
			k = 0;
			while (--j >= 0)
				board[i][j] = ++k;
		}
	}

}

void	ft_fillfour(int board[][4], char **tab)
{
	int	column;

	column = -1;
	while (tab[0][++column])
	{
		if (tab[0][column] == '1')		//VERIFY COLUMNS
			board[0][column] = 4;
		if (tab[1][column] == '1')		//VERIFY COLUMNS
			board[3][column] = 4;
		if (tab[2][column] == '1')		//VERIFY ROWS
			board[column][0] = 4;
		if (tab[3][column] == '1')		//VERIFY ROWS
			board[column][3] = 4;
	}
	if (ft_verify_cell(board, 1, 1, 4) && (tab[1][1] == '3' || tab[3][1] == '3'))
		board[1][1] = 4;
	if (ft_verify_cell(board, 1, 2, 4) && (tab[1][2] == '3' || tab[2][1] == '3'))
		board[1][2] = 4;
	if (ft_verify_cell(board, 2, 1, 4) && (tab[0][1] == '3' || tab[3][2] == '3'))
		board[2][1] = 4;
	if (ft_verify_cell(board, 2, 2, 4) && (tab[0][2] == '3' || tab[2][2] == '3'))
		board[2][2] = 4;
}

void	random_solutions(int board[][4], char **tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		if (tab[0][i] == '2' && tab[1][i] == '1')
			board[0][i] = 3;
		if (tab[1][i] == '2' && tab[0][i] == '1')
			board[3][i] = 3;
		if (tab[0][i] == '3' && !ft_verify_cell(board, i, 0, 1))
			board[0][i] == 2;
		if (tab[0][i] == '3' && !ft_verify_cell(board, i, 0, 2))
			board[0][i] == 1;
		if (tab[1][i] == '3' && !ft_verify_cell(board, i, 3, 1))
			board[3][i] == 2;
		if (tab[1][i] == '3' && !ft_verify_cell(board, i, 3, 2))
			board[3][i] == 1;
	}
	
}

void	ft_interation(int board[][4], char **tab)


void	ft_do_the_things(int board[][4], char **tab)
{
	ft_fillfour(board, tab);
	ft_check_four_vertical(board, tab);
	ft_check_four_horizontal(board, tab);
	random_solutions(board, tab);
}

char	**ft_filltab(char **columns, char *src)
{
	int	pos;
	int	i;

	pos = -1;
	while (++pos < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (*src == ' ')
				src++;
			columns[pos][i] = *src++;
		}
		columns[pos][i] = '\0';
	}
	columns[pos] = '\0';
	return (columns);
}

char	**ft_malloc(char *src)
{
	int		pos;
	char	**columns;

	columns = malloc(sizeof(char *) * 4);
	if (columns == NULL)
		return NULL;
	pos = -1;
	while (++pos < 4)
	{
		columns[pos] = malloc(sizeof(char) * 4);
		if (columns[pos] == NULL)
		{
			pos = -1;
			while (columns[pos])
				free(columns[pos]);
			free(columns);
			return (NULL);
		}
	}
	return (ft_filltab(columns, src));
}


int main(int ac, char **av)
{
	int		row[4][4];
	int		c;
	int		i;
	char	dest[16];
 
	if (ac < 2)
		return (0);
	i = -1;
	while (++i < 4)
	{
	  c = -1;
	  while (++c < 4)
	    row[i][c] = 0;
	}
	i = -1;
	ft_strncpy(dest, av[1], 16);
	av = ft_malloc(dest);
	ft_do_the_things(row, av);
	ft_print_table(row);
	while (av[++i])
		free(av[i]);
	free(av);
}
