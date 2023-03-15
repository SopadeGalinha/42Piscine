/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:18:16 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 01:18:16 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = -1;
    while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
/*
int	main(int ac, char **av)
{
	char	dest[20];
	char	o_dest[20];
	
	if (ac < 2)
		return (printf("Put something to test dumass"));
	if (strlen(av[1]) > 20)
		return (printf("Try a smaller string"));
	strncpy(o_dest, av[1], atoi(av[2]));	
	ft_strncpy(dest, av[1], atoi(av[2]));	
	printf("Original: [%s]\n", o_dest);
	printf("Mine    : [%s]\n", dest);
	return (0);
}
*/
