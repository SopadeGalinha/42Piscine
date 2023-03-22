/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:42:06 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/22 19:06:41 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Reproduce the behavior of the function strlcat (man strlcat)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = ft_strlen(dest);
	dest_len = i;
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	while (*src != '\0' && i < size - 1)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

/*
int	main(int ac, char **av)
{
	char	*dest;
	int		c;

	if (ac < 2)
		return (printf("Missing input\n"));
	c = ft_strlcat(av[1], av[2], atoi(av[3]));
	printf("%d\n", c);
	printf("%s\n", av[1]);
	return (0);
}
*/
