/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:53:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 08:53:43 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//  • Create a function that displays the alphabet in lowercase, on a single line, by
//   ascending order, starting from the letter ’a’.

#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_alphabet(void)
{
    char    letter;

    letter = 'a';
    while (letter != 'z')
     {
        ft_putchar(letter);
        letter++;
     }
        ft_putchar(letter);
}

/*
int main(void)
{
    ft_print_alphabet();
    ft_putchar('\n');
    return (0);
}
*/