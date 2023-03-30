/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:29:18 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:29:18 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//Create a function that displays a string of characters on the standard output

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/*
int main(void)
{
    ft_putstr("SopadeGalinha\n");
    return 0;
}
*/