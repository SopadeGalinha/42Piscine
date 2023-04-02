/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:20:43 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:20:43 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// •This function divides parameters a by b.
//  The result of this division is stored in the
// int pointed by a. The remainder of the 
// division is stored in the int pointed by b.

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	x;

	if (*b == 0)
		return ;
	x = *a % *b;
	*a = *a / *b;
	*b = x;
}

/*
int		main(void)
{
	int i = 10;
	int j = 5;
	int *a = &i;
	int *b = &j;

	printf("%d /",i);
	printf(" %d\n",j);

	ft_ultimate_div_mod(a, b);
	
	printf("div (*a) = %d\n",*a);
	printf("mod (*b) = %d",*b);
}
*/