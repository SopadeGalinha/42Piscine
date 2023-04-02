/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:22:06 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 19:22:06 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//Create a function that takes a pointer to
// pointer to pointer to pointer to pointer
// to pointer to pointer to pointer to pointer	
// to int as a parameter and sets the value
// "42" to that int.

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*
int		main (void)
{
	int *********p_nbr;
	int ********p_nbr2;
	int *******p_nbr3;
	int ******p_nbr4;
	int *****p_nbr5;
	int ****p_nbr6;
	int ***p_nbr7;
	int **p_nbr8;
	int *p_nbr9;
	int nbr;

	nbr = 13;
	p_nbr9 = &nbr;
	p_nbr8 = &p_nbr9;
	p_nbr7 = &p_nbr8;
	p_nbr6 = &p_nbr7;
	p_nbr5 = &p_nbr6;
	p_nbr4 = &p_nbr5;
	p_nbr3 = &p_nbr4;
	p_nbr2 = &p_nbr3;
	p_nbr = &p_nbr2;

	printf("%d\n", nbr);
	return (0);
}
*/