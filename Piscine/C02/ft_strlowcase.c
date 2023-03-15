/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:57:30 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 21:57:30 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
• Create a function that capitalizes the first letter of each word and transforms all
other letters to lowercase.
• A word is a string of alphanumeric characters.
• Here’s how it should be prototyped :
*/

char	*ft_strupcase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	return (str);
}
/*
int	main(int ac, char **av)
{
	if (ac < 2)
		return (printf("I need an argument fella\n"));
	printf(":%s:\n", ft_strupcase(av[1]));
	return (0);
}
*/
