/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:01:30 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/19 13:43:43 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Reproduce the behavior of the function strstr (man strstr).

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		h;
	int		n;

	if (!str || !to_find)
		return (str);
	h = -1;
	while (str[++h] != '\0')
	{
		n = 0;
		while (str[h + n] != '\0' && str[h + n] == to_find[n])
			n++;
		if (to_find[n] == '\0')
			return (str + n);
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac < 2)
		return (printf("U must put something after './a.out'"));
	printf("Result: %s\n", strstr(av[1], av[2]));
	return (0);
}
*/
