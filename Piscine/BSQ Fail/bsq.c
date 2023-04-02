/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rboia-pe@student.42porto.com  <rboia-p    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:11 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/29 12:34:20 by  rboia-pe@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	beautiful_colors(int i, int j, char **grid)
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
			beautiful_colors(i, j, grid);
		}
		write (1, "\n", 1);
	}
}

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	calculate_size(char **grid, int rows, int cols, int **size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols - 1)
		{
			  if (grid[i][j] == 'o')
					size[i][j] = 0;
            else if (i == 0 || j == 0)
					size[i][j] = 1;
            else
                size[i][j] = 1 + ft_min_int(size[i - 1][j], ft_min_int(size[i][j - 1], size[i - 1][j - 1]));
		}
	}
}

void	max_square_coords_helper(int *pos, int **size, int *max_xy_size)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	rows = pos[1];
	cols = pos[0];
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (size[i][j] > max_xy_size[2])
			{
				max_xy_size[2] = size[i][j];
				max_xy_size[0] = j - max_xy_size[2] + 1;
				max_xy_size[1] = i - max_xy_size[2] + 1;
			}
		}
	}
}

void	max_coords(char **grid, int *pos, int *max_xy_size)
{
	int	**size;
	int	i;
	int	rows;
	int	cols;

	i = -1;
	cols = pos[0];
	rows = pos[1];
	size = (int **)malloc(rows * sizeof(int *));
	if (size == NULL)
	{
		write (1, "Error\n", 6);
		exit (2);
	}
	while (++i < rows)
	{
		size[i] = (int *)malloc(cols * sizeof(int));
		if (size[i] == NULL)
		{
			write (1, "Error\n", 6);
			exit (2);
		}
	}
	calculate_size(grid, rows, cols, size);
	max_xy_size[2] = 0;
	i = -1;
	max_square_coords_helper(pos, size, max_xy_size);
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

void	mark_square(char **grid, int *pos, int *max_xy_size)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = pos[0];
	y = pos[1];
	i = max_xy_size[1] - 1;
	while (++i < max_xy_size[1] + max_xy_size[2])
	{
		j = max_xy_size[0] - 1;
		while (++j < max_xy_size[0] + max_xy_size[2])
			if (grid[i][j] != 'o')
				grid[i][j] = 'x';
	}
	write (1, "\n", 1);
	ft_print_grid(grid, y, x);
	i = -1;
	while (++i < y)
		free(grid[i]);
	free(grid);
}

void	ft_find_largest_square(char **grid, int x, int y)
{
	int	max_xy_size[3];
	int	pos[2];

	pos[1] = y;
	pos[0] = x;
	max_coords(grid, pos, max_xy_size);
	write (1, "\nSize of largest square: ", 25);
	ft_putnbr(max_xy_size[2]);
	write (1, "\n", 1);
	write (1, "Upper-left corner coordinates: (", 33);
	ft_putnbr(max_xy_size[0]);
	write (1, ", ", 2);
	ft_putnbr(max_xy_size[1]);
	write (1, ")\n", 2);
	mark_square(grid, pos, max_xy_size);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

char    **ft_read_txt(char **grid, int *xy, char **argv, int argc)
{
    int	i;
	int	j;
	int fd;
	char	buf;

    fd = open(argv[argc - 1], O_RDONLY); 
	i = 0;
	j = 0;
    while (read(fd, &buf, 1) > 0)//enquanto o ficheiro indicado por fd estiver valido (> 0)
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
		if (i > 0 && (buf != '.' && buf != 'o' && buf != '\n'))
		{
			write (1, "Mapa inválido\n", 15);
			exit(0);
		}
    }
	
    close(fd); // Fechar o arquivo
    printf("\n%s\n", grid[0]);
	return (grid);
}