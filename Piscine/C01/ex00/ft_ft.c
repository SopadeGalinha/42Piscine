/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:54:32 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/05 15:54:32 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function that takes a pointer to
// int as a parameter, and sets the value "42"
// to that int.

#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*
int main(void)
{
    int n;
    int *nb;

    n = 7;
    nb = &n;
    ft_ft(nb);
    printf(":%d: ", n);
    return 0;
}
*/