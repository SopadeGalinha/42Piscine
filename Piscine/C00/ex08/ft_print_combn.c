/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:01:46 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 21:01:46 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a function that displays all different combinations
// of n numbers by ascending
// order.
// • n will be so that : 0 < n < 10.
// • If n = 2, here’s the expected output :
// $>./a.out | cat -e
// 01, 02, 03, ..., 09, 12, ..., 79, 89$>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combn(int n, int index, int tab[], int c_position)
{
	int	c;

	if (index == n)
	{
		c = 0;
		while (c < n)
			ft_putchar(tab[c++] + '0');
		if (tab[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	if (c_position == 10)
		return ;
	tab[index] = c_position;
	print_combn(n, index + 1, tab, c_position + 1);
	print_combn(n, index, tab, c_position + 1);
}

void	ft_print_combn(int n)
{
	int	tab[10];

	if (n < 1 || n > 9)
		return ;
	print_combn(n, 0, tab, 0);
}

/*
int	main(void)
{
	ft_print_combn(1);
}
*/