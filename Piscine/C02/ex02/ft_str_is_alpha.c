/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:10:15 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 07:10:15 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	c;

	c = -1;
	while (str[++c])
		if ((str[c] < 'A' || (str[c] > 'z')) || (str[c] > 'Z' && str[c] < 'a'))
			return (0);
	return (1);
}
/*
int	main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Put something after the executable\n"));
	if (ft_str_is_alpha(av[1]))
		printf("Is alpha\n");
	else
		printf("Is not alpha\n");
	return 0;	
}
*/
