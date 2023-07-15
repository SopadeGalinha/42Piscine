/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:01:30 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/19 14:40:59 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	bool	ndl;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		ndl = true;
		j = 0;
		while (to_find[j] != '\0' && ndl)
		{
			if (str[i + j] != to_find[j])
				ndl = false;
			j++;
		}
		if (ndl)
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int		main(void)
{
	char str[] = "012340123456789";
	char to_find[] = "456";

	printf("STR: %s\nTo FIND:  %s\n", str, to_find);
	printf("Result: %s\n", ft_strstr(str, to_find));

	return (0);
}
*/
