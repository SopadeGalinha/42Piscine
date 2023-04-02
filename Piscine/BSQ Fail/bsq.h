/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  rboia-pe@student.42porto.com  <rboia-p    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:20 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/28 09:37:17 by  rboia-pe@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	max_coords(char **grid, int *pos, int *max_xy_size);
void	ft_find_largest_square(char **grid, int x, int y);
void	mark_square(char **grid, int *pos, int *max_xy_size);
void	ft_putnbr(int n);
void	max_square_coords_helper(int *pos, int **size, int *max_xy_size);
void	ft_print_grid(char **grid, int rows, int cols);
void	calculate_size(char **grid, int rows, int cols, int **size);
int	    ft_min_int(int a, int b);
void	beautiful_colors(int i, int j, char **grid);
int     ft_atoi(const char *str);
char    **ft_read_txt(char **grid, int *xy, char **argv, int argc);

#endif