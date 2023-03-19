
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
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

void	ft_print_table(int board[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(board[i][j] + '0');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
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

int	ft_verify_column_t0(int board[4][4], char **tab)
{
	int	column;
	int	j;
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
	int	j;
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
	int	j;
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
	int	j;
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

void ft_combinations(int matrix[4][4], int row, int col, char **tab) 
{
	int num;
	int static c;

	c = 0;
    if (row == 4) 
	{
	    if (ft_verify_row_t3(matrix, tab) == 1)
			if (ft_verify_column_t0(matrix, tab) == 1) 
				if (ft_verify_column_t1(matrix, tab) == 1)
					ft_print_table(matrix);
	}			
					
    if (col == 4)
	{
        // Proxima linha
		ft_combinations(matrix, row + 1, 0, tab);
        return;
    }
	
	num = 0;
    // Tenta os numeros de 1 a 4 na celula
    while (++num <= 4) 
	{
        if (is_valid(matrix, row, col, num)) 
		{
            matrix[row][col] = num;
            ft_combinations(matrix, row, col + 1, tab);
            matrix[row][col] = 0;
        }
    }
}

int main(int ac, char **av)
{
	int		board[4][4];
	int		c;
	int		i;
	char	dest[16];
	char	**tab;
 
	if (ac < 2)
		return (0);
	i = -1;
	while (++i < 4)
	{
	  c = -1;
	  while (++c < 4)
	    board[i][c] = 0;
	}
	ft_strncpy(dest, av[1], 16);
	tab = ft_malloc(dest);
	ft_combinations(board, 0, 0, tab);
	i = 4;
	while (--i >= 0)
		while (tab[i])
	 		free(tab[i]);
	free(tab);
	return (0);
}
