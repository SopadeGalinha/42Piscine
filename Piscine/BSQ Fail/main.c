/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:17 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/29 23:37:20 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>
#include <stdbool.h>

bool check_matrix(char **matrix, int n) {
    int i = 0;
    int first_len = -1;
    while (i < n)
    {
        int len = ft_strlen(matrix[i]);
        if (first_len == -1)
        {
            first_len = len;
        } else if (first_len != len)
        {
            return false;
        }
        i++;
    }
    return true;
}

#include "bsq.h"

int main(int argc, char **argv)
{
	int i = -1;
	int	x;
	int	y;
	int	density;
	int xy[2];
	char	**grid;
	char **grid_temp;

	if (argc == 1)
		return (0);
    x = ft_atoi(argv[1]);
    y = x;
    xy[0] = x;
    xy[1] = y;
    grid = (char **) malloc(xy[1] * sizeof(char *));
    grid_temp = (char **) malloc(xy[1] * sizeof(char *));
    while (++i < xy[1])
    {
		  grid[i] = (char *) malloc(xy[0] * sizeof(char));
      grid_temp[i] = (char *) malloc(xy[0] * sizeof(char));
    }
    grid = ft_read_txt(grid_temp, x, argv, argc);
    i = -1;
	if (!check_matrix(grid, x))
		return (0);	
	ft_print_grid(grid, y, x);
	ft_find_largest_square(grid, x, y);
    return (0);
}
