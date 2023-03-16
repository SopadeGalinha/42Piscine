/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 11:42:06 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:01 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int	counter(char *src)
{
	int	c;
	int	h;

	h = 0;
	c = 0;
	while (src[c] != '\0')
	{
		h = src[c];
		c++;		
	}
	return (h);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = counter(src);
	while (dest[i] != '\0' && i < size)
	{
		dest[x] = src[i];
		x++;
		i++;
	}
	return (x);
}

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				main()
{
	char			str0[50];
	char			str1[50];
	char			str2[] = "Concatenando 1";
	unsigned int	tamanho1;
	unsigned int	tamanho2;
	int	size;

	str0[0] = 'O';
	str0[1] = 'l';
	str0[2] = 'a';
	str0[3] = '\0';

	str1[0] = 'O';
	str1[1] = 'l';
	str1[2] = 'a';
	str1[3] = '\0';
	size = 15;

	tamanho1 = ft_strlcat(str0, str2, 0);
	tamanho2 = strlcat(str1, str2, 0);
	printf("String final: %s, Tamanho: %d", str0, tamanho1);
	printf("\nString final: %s, Tamanho: %d", str1, tamanho2);
	printf("\n\nOriginal: %s\n O meu: %s", tamanho2(dest, src, size), tamanho1(dest, src, size))
}
