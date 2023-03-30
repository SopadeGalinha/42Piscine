/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:58:08 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 10:58:08 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function that displays all different combination of two two 
// digits numbers (XX XX) between 00 and 99, listed by ascending order.

// Here’s the expected output :
// $>./a.out | cat -e
// 00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int n1, int n2)
{
	ft_putchar(n1 / 10 + '0');
	ft_putchar(n1 % 10 + '0');
	ft_putchar(' ');
	ft_putchar(n2 / 10 + '0');
	ft_putchar(n2 % 10 + '0');
	if (n1 + n2 != 197)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 <= 98)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			ft_print_numbers(n1, n2);
			n2++;
		}
		n1++;
	}
}

/*
int main(void)
{
    ft_print_comb2();
}
*/