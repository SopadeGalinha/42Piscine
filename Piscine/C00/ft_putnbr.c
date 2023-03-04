/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:53:07 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 19:53:07 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function that displays the number entered as a parameter.
// The function has to be able to display all possible values within
// an int type variable.
// • Here’s how it should be prototyped :

#include<unistd.h>

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-21", 3);
        nb = 47483648;
    }
    if (nb < 0)
    {
        nb *= -1;
        write(1, "-", 1);
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
        write(1, &"0123456789"[nb], 1);
}

/*
int main(void)
{
    ft_putnbr(-5);
    write(1, "\n", 1);
    ft_putnbr(0);
    write(1, "\n", 1);
    ft_putnbr(5);
    write(1, "\n", 1);
    ft_putnbr(2147483647);
    write(1, "\n", 1);
    ft_putnbr(-2147483648);
}
*/
