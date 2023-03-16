/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:07:36 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/19 14:18:28 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	counter( char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c;

	c = counter(dest);
	while (*src != '\0')
	{
		dest[c] = *src;
		c++;
		src++;
	}
	dest[c] = '\0';
	return (dest);
}
/*
char *ft_strcat(char *dest, char *src);
int main(void)
{
	char	src [50] = " wanna some candy?";
	char	dest[50] = "Sup kiddo,"

	printf("BFF DST: %s", dest);
	ft_strcat(dest, src);
	printf("\nBFF SRC: %s", src);
	printf("\nResult: %s  ", dest);

}
*/
