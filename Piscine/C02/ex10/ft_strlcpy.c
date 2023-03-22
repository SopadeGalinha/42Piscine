/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:12:38 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 22:12:38 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;

	i = -1;
	c = -1;
	while (src[++c] != '\0')
		;
	if (size != 0)
		while (src[++i] != '\0' && i < size - 1)
			dest[i] = src[i];
	dest[i] = '\0';
	return (c);
}
/*
int	main(int ac, char **av)
{
	char dest[20];-

	if (ac < 2)
		return (printf("Missing arguments?\n"));
	printf("%d\n", ft_strlcpy(dest, av[1], atoi(av[2])));
}
*/
