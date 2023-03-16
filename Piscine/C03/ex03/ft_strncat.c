/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:09:11 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/20 12:38:53 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	contsize(char *c)
{
	int	a;

	a = 0;
	while (c[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				sd;
	unsigned int	i;

	i = 0;
	sd = contsize(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[sd + i] = src[i];
		i++;
	}
	dest[sd + i] = '\0';
	return (dest);
}
/*
 int main()
{
    char    src[] = "U number?";
    char    dest[15] = "Can I have ";
    unsigned int  nb = 8;

    printf("Dest BFF: %s\n", dest);
    printf("Src BFF: %s\n", src);
    printf("Num of char: %d\n", nb);
    printf("Dest AFT: %s", dest);
}
*/
