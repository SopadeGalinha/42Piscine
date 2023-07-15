/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:25:07 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/12 20:19:36 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int row, int column, char *catia, int slash_n)
{
	int	i;

	i = 1;
	ft_putchar(catia[0]);
	while (++i < row)
		ft_putchar(catia[1]);
	if (row > 1)
		ft_putchar(catia[2]);
	if (slash_n && column > 1)
		ft_putchar(catia[3]);
}

void	rush(int x, int y)
{
	int		i;
	char	*catia[3];

	if (x < 1 || y < 1)
		return ;
	i = 1;
	catia[0] = "/*\\\n";
	catia[1] = "* *\n";
	catia[2] = "\\*/\n";
	ft_print(x, y, catia[0], 1);
	while (++i < y)
		ft_print(x, y, catia[1], 1);
	if (y > 1)
		ft_print(x, y, catia[2], 0);
}
