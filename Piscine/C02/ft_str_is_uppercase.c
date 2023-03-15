/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:21:55 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 21:21:55 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_uppercase(char *str)
{
	while (*str)
		if(*str < 'A' || *str++ > 'Z')
			return (0);
	return (1);

}
/*
int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Hey, put something after the .a.out"));
	if (ft_str_is_uppercase(av[1]))
		return (printf("Itss Upper!"));
	return (printf("Nops"));
}
*/
