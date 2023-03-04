/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:54:37 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 08:54:37 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a function that displays all digits, on a single line, by ascending order.

#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_numbers(void)
{
    char    nb;

    nb = '0';
    while (nb <= '9')
    {
        ft_putchar(nb);
        nb++;
    }
}

/*
int main(void)
{
    ft_print_numbers();
    ft_putchar('\n');
    return (0);
}
*/