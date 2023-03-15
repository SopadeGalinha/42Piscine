/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:24:34 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 07:24:34 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (*str)
		if ((*str < '0') || (*str++ > '9'))
			return (0);
	return (1);
}

/*
int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("you need to put something after the exec(a.out).\n"));
	if (ft_str_is_numeric(av[1]))
		printf("OK\n");
	else
		printf("Not numeric\n");
	return 0;

}
*/
