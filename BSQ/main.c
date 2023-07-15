/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rboia-pe@student.42porto.com  <rboia-p    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:17 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/29 10:43:35 by  rboia-pe@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char **argv)
{
  int i = -1;
  int  j;
  int  density;
  int xy[2];
  char  **grid;
  char **grid_temp;

  if (argc == 1)
    write (1, "Error\n", 6);
  else if (argc == 2)
  {
    xy[0] = 10;
    xy[1] = 10;
  }
  else
  {
    xy[0] = ft_atoi(argv[1]) + 1;
    xy[1] = xy[0];
  }
    grid = (char **) malloc(xy[1] * sizeof(char *));
    if (grid == NULL)
    {
      write (1, "Error\n", 6);
      exit (2);
    }
    grid_temp = (char **) malloc(xy[1] * sizeof(char *));
    if (grid_temp == NULL)
    {
      write (1, "Error\n", 6);
      exit (2);
    }
    while (++i < xy[1])
    {
      grid[i] = (char *) malloc(xy[0] * sizeof(char));
      if (grid[i] == NULL)
      {
        write (1, "Error\n", 6);
        exit (2);
      }
      grid_temp[i] = (char *) malloc(xy[0] * sizeof(char));
      if (grid_temp[i] == NULL)
      {
        write (1, "Error\n", 6);
        exit (2);
      }
    }
    ft_read_txt(grid_temp, xy, argv, argc);
    i = 0;
    while(++i < xy[0])
    {
      j = -1;
      while(j++ < xy[1] - 1)
        grid[i - 1][j] = grid_temp[i][j];
    }
    ft_print_grid(grid, xy[1], xy[0]);
    ft_find_largest_square(grid, xy[0], xy[1]);
    i = -1;
    while (++i < xy[1])
        free(grid_temp[i]);
    free(grid_temp);
    return (0);
}
