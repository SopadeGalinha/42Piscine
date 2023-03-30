/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:54:34 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:54:34 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function which sorts an array of integers by ascending order.
// • The arguments are a pointer to int and the number of ints in the array.

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	c;
	int	swap;

	c = -1;
	while (++c < (size - 1))
	{
		if (tab[c] > tab[c + 1])
		{
			swap = tab[c];
			tab[c] = tab[c + 1];
			tab[c + 1] = swap;
			c = -1;
		}
	}
}
/*
int main(void)
{
    int tab[] = {5, 3, 4, 2, 6, 1};
    int i = 0;
    
        printf("Antes  :");
    while (i < 6)
        printf("[ %d ]", tab[i++]);
    i = 0;
    ft_sort_int_tab(tab, 6);
    printf("\nDepois :");
    while (i < 6)
        printf("[ %d ]", tab[i++]);
}
*/