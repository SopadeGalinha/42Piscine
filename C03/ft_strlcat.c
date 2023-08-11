/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:42:06 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/23 01:26:51 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *src)
{
	int	c;

	c = 0;
	while (src[c] != '\0')
		c++;
	return (c);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
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
