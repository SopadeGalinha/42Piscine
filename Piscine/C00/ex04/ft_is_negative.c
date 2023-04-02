/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:02:06 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/04 09:02:06 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a function that displays ’N’ or ’P’
// depending on the integer’s sign entered
// as a parameter. If n is negative, display ’N’.
// If n is positive or null, display ’P’.

#include<unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
int main(void)
{
int nb;
	nb = -1;
ft_is_negative(nb);
return (0);
}
*/
