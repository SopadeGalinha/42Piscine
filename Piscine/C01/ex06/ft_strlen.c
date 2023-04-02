/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:37:10 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/07 23:37:10 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// • Create a function that counts and returns
// the number of characters in a string.

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

/*
int	main(void)
{
	printf("%d", ft_strlen("Sopa"));
	return (0);
}
*/