/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:11 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/29 23:36:41 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_grid(char **grid, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (grid[i][j] == 'x')
			{
				write (1, "\033[32m", 5);
				write (1, &grid[i][j], 1);
				write (1, "\033[0m", 4);
			}
			else if (grid[i][j] == 'o')
			{
				write (1, "\033[31m", 5);
				write (1, &grid[i][j], 1);
				write (1, "\033[0m", 4);
		            }
            else
              write (1, &grid[i][j], 1);
        }
        write (1, "\n", 1);
    }
}


int ft_min_int(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void calculate_size(char **grid, int rows, int cols, int **size)
{
	int i;
	int j;

	i = 0;
	while (++i < rows)
    {
		if (grid[i][j] == 'o' || grid[i][j] == '.' || grid[i][j] == 'x')
		{
			j = -1;
			while (++j < cols)
			{
				if (grid[i][j] == 'o')
					size[i][j] = 0;
				else if (i == 0 || j == 0)
					size[i][j] = 1;
				else
					size[i][j] = 1 + ft_min_int(size[i-1][j], ft_min_int(size[i][j-1], size[i-1][j-1]));
			}
		}
	}
}

void	max_square_coords_helper(int *pos,int **size, int *max_size, int *max_x, int *max_y)
{
	int	rows;
	int	cols;

	int i;
	int j;
	rows = pos[1];
	cols = pos[0];

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (size[i][j] > *max_size)
			{
				*max_size = size[i][j];
				*max_x = j - *max_size + 1;
				*max_y = i - *max_size + 1;
			}
		}
	}
}

void max_coords(char **grid, int *pos, int *max_size, int *max_x, int *max_y)
{
	int **size;
	int i;
	int j;
	int rows;
	int cols;

	i = -1;
	rows = pos[1];
	cols = pos[0];
	size = (int **)malloc(rows * sizeof(int *));
	while (++i < rows)
		size[i] = (int *)malloc(cols * sizeof(int));
	calculate_size(grid, rows, cols, size);
	*max_size = 0;
	i = -1;
	i = -1;
	max_square_coords_helper(pos, size, max_size, max_x, max_y);
	while (++i < rows)
		free(size[i]);
	free(size);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		write(1, &"0123456789"[n], 1);
}

void	mark_square(char **grid, int *pos, int max_x, int max_y, int max_size)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	i = max_y - 1;
	while (++i < max_y + max_size)
	{
		j = max_x - 1;
		while (++j < max_x + max_size)
			if (grid[i][j] != 'o')
				grid[i][j] = 'x';
	}
	i = -1;
	write(1, "\n", 1);
	ft_print_grid(grid, y, x);
	while (++i < y)
		free(grid[i]);
	free(grid);
}

void	ft_find_largest_square(char **grid, int x, int y)
{
	int	max_size;
	int	max_x;
	int	max_y;
	int	pos[2];

	pos[1] = y;
	pos[0] = x;
	max_x = 0;
	max_y = 0;
	max_size = 0;


	max_coords(grid, pos, &max_size, &max_x, &max_y);
	write (1, "\nSize of largest square: ", 25);
	ft_putnbr(max_size);
	write (1, "\n", 1);
	write (1, "Upper-left corner coordinates: (", 33);
	ft_putnbr(max_x);
	write (1, ", ", 2);
	ft_putnbr(max_y);
	write (1, ")\n", 1);
	mark_square(grid, pos, max_x, max_y, max_size);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	negative = 0;
	int	number = 0;

	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	while ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	if (negative % 2 != 0)
		return (number * -1);
	return (number);
}

char    **ft_read_txt(char **grid, int x, char **argv, int argc)
{
    int		i;
	int		j;
	int		fd;
	char	buf;

    fd = open(argv[argc - 1], O_RDONLY); 
	i = 0;
	j = 0;
    while ((read(fd, &buf, 1) > 0) && i < x)//enquanto o ficheiro indicado por fd estiver valido (> 0)
    {
        if (buf == '\n')//verifica se o char buf contem uma quebra de linha
		{
            i++;
            j = 0;
        }
		else
        {
            grid[i][j] = buf;
			j++;
        }
    }
    close(fd); 
	return (grid);
}


int	ft_txt_is_valid(char **grid)
{
	int	i;
	int	j;


	i = -1;
	j = -1;
	while (grid[++i])
	{
		while (grid[i][++j])
		{
			if (grid[i][++j] == 'o')
				;
			else if ((grid[i][++j] == 'x'))
				;
			else if ((grid[i][++j] == '.'))
				;
			else if ((grid[i][++j] == '\n'))
				;
			else
				return (0);
		}
	}
	return (1);
}
int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}
