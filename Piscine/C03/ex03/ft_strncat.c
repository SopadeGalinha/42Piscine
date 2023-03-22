/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:09:11 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/22 19:15:58 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, const char *src, unsigned int nb)
{
	unsigned int	size_dest;
	unsigned int	i;

	i = -1;
	size_dest = ft_strlen(dest);
	while (src[++i] != '\0' && i < nb)
		dest[size_dest + i] = src[i];
	dest[size_dest + i] = '\0';
	return (dest);
}
/*
int	main(int ac, char **av)
{
	char	dest[25] = "42PORTO";
	char	dest_c[25] = "42PORTO";
	char	src[15]	= "Network";
	printf("%s\n", dest);
	printf("Org: %s\n", strncat(dest, src, 5));
	printf("Cpy: %s\n", ft_strncat(dest_c, src, 5));
}
*/
