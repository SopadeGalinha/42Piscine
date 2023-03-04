/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:06:56 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 09:06:56 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a function that displays all different combinations of three different digits in
// ascending order, listed by ascending order - yes, repetition is voluntary.

// • Here’s the intended output:
// $>./a.out | cat -e
// 012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>

//  987 isn’t there because 789 already is.
// • 999 isn’t there because the digit 9 is present more than once.

#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_numbers(int n1, int n2, int n3)
{
    ft_putchar(n1 + '0');
    ft_putchar(n2 + '0');
    ft_putchar(n3 + '0');
    if (n1 + n2 + n3 != 24)
        write(1, ", ", 2);
}

void    ft_print_comb(void)
{
    int n1;
    int n2;
    int n3;

    n1 = 0;
    while (n1 <= 7)
    {
        n2 = n1 + 1;
        while (n2 <= 8)
        {
            n3 = n2 + 1;
            while (n3 <= 9)
            {
                ft_print_numbers(n1, n2, n3);
                n3++;
            }
            n2++;
        }
        n1++;
    }
}

int main(void)
{
    ft_print_comb();
    return (0);
}