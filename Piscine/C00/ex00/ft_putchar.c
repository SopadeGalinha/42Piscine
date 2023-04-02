/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:53:53 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 08:53:53 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Write a function that displays the character passed as a parameter

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
int main(void)
{
    ft_putchar('4');
    ft_putchar('2');
    ft_putchar('\n');
    return (0);
}
*/
