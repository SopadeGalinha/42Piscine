/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:09:11 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/23 01:19:18 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *c)
{
	int	i;

	i = -1;
	while (c[++i] != '\0')
		;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				sd;
	unsigned int	i;

	i = -1;
	sd = ft_strlen(dest);
	while (src[++i] != '\0' && i < nb)
		dest[sd + i] = src[i];
	dest[sd + i] = '\0';
	return (dest);
}
/*
int main()
{
    char    src[] = "U number?";
    char    dest[30] = "Can I have ";
    unsigned int  nb = 12;

	ft_strncat(dest, src, nb);
    printf("Dest BFF: %s\n", dest);
    printf("Src BFF: %s\n", src);
    printf("Num of char: %d\n", nb);
    printf("Dest AFT: :%s:\n", dest);
}
*/
