/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:40:20 by  rboia-pe@s       #+#    #+#             */
/*   Updated: 2023/03/29 23:37:55 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <time.h>

int	ft_strlen(char *str);
void    max_coords(char **grid, int *pos, int *max_size, int *max_x, int *max_y);
void	ft_find_largest_square(char **grid, int x, int y);
void	mark_square(char **grid, int *pos, int max_x, int max_y, int max_size);
void	ft_putnbr(int n);
void	max_square_coords_helper(int *pos,int **size, int *max_size, int *max_x, int *max_y);
void	ft_print_grid(char **grid, int rows, int cols);
void	calculate_size(char **grid, int rows, int cols, int **size);
int	    ft_min_int(int a, int b);
void	beautiful_colors(int i, int j, char **grid);
int ft_atoi(char *str);
char    **ft_read_txt(char **grid, int x, char **argv, int argc);

#endif
