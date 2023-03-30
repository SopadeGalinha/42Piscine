/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:46:29 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 22:46:29 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function that swaps the value of two 
// integers whose addresses are entered
// as parameters.

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

/*
int		main(void)
{
	int i  = 7;
	int j  = 3;

	int *a = &i;
	int *b = &j;

	ft_swap(a, b);
	printf("a was 7 and now is: %u\n", *a);
	printf("b was 3 and now is: %u\n", *b);
    return(0);
}
*/