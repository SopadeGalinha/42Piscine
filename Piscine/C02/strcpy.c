/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:09:44 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 01:09:44 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}

/*
int main(int ac, char **av)
{
    char    dest[20];
    char    dest_o[20];
    if (ac < 2)
        return 0;
    if (strlen(av[1]) > 20)
        return (printf("your string is to big, try again"));
	strcpy(dest_o, av[1]);
	ft_strcpy(dest, av[1]);
	printf("ORIGINAL: [%s]\n", dest_o);
	printf("MINE    : [%s]\n", dest_o);
	return 0;
}
*/