/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:37:54 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 07:37:54 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str)
		if (*str < 'a' || *str++ > 'z')
			return (0);
	return (1);
}

/*
int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("you need to put something after the exec(a.out).\n"));
	if (ft_str_is_lowercase(av[1]))
		printf("Str is lower!\n");
	else
		printf("Str is not lowercase\n");
	return 0;
}
*/