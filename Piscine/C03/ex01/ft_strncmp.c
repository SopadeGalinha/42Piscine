/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:21:46 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/21 11:31:29 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int ft_strncmp(char *s1, char *s2, unsigned int n);
int	main(void)
{
	char			*s1;
	char			*s2;
	unsigned int	n;

	s1 = "Me testa ae";
	s2 = "Metesta ai";
	n = 3;
	printf("strcmp is: %i\n", strncmp(s1, s2, n));
	printf("ft_strcmp is: %i\n", ft_strncmp(s1, s2, n));
}
*/
