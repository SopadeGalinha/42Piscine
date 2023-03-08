/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:40:37 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:40:37 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	b;
	int	swap;

	i = 0;
	b = size - 1;
	while (i < (size / 2))
	{
		swap = tab[i];
		tab[i] = tab[b];
		tab[b] = swap;
		i++;
		b--;
	}
}

/*
int main(void)
{
    int tab[] = {1, 2, 3, 4, 5, 6, 7};
    int i = 0;
    int size = 7;

    printf("Antes  :");
    while (i < size)
        printf("[ %d ]", tab[i++]);
    ft_rev_int_tab(tab, size);
    i = 0;
    printf("\nDepois :");
    while (i < size)
        printf("[ %d ]", tab[i++]);
}
*/