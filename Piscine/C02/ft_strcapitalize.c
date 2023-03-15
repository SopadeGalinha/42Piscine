/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:42:41 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 07:42:41 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (str[c] != '\0')
	{
		if (i == 0 && (str[c] >= 'a' && str[c] <= 'z'))
		{
			str[c] -= 32;
			i++;
		}
		else if (i > 0 && (str[c] >= 'A' && str[c] <= 'Z'))
			str[c] = str[c] + 32;
		else if ((str[c] < '0') || (str[c] > '9' && str[c] < 'A'))
			i = 0;
		else if ((str[c] > 'Z' && str[c] < 'a') || (str[c] > 'z'))
			i = 0;
		else
			i++;
		c++;
	}
	return (str);
}
/*
int main(int ac, char **av)
{
    if (ac < 2)
     return (printf("you need to put something after the exec(a.out).\n"));
 
    printf("Antes : %s\n", ft_strcapitalize(av[1]));
    printf("Depois: %s\n", ft_strcapitalize(av[1]));
    return 0;
}
*/