/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:02:38 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:02:38 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • This function divides parameters a by 
// b and stores the result in the int pointed by
// div. It also stores the remainder of the division 
// of a by b in the int pointed by mod

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
		return ;
	*div = a / b;
	*mod = a % b;
}

/*
int main(void)
{
	int a  = 5;
	int b  = 2;

	int *div = &a;
	int *modulo = &b;

	ft_div_mod(a, b, div, modulo);
	
	printf("Div: %d\n",*div);
	printf("Mod: %d\n",*modulo);
}
*/