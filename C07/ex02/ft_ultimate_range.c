/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:56:10 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/26 18:53:37 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tmp;

	i = 0;
	if (min >= max)
		return (0);
	tmp = malloc(sizeof(int) * (max - min));
	if (tmp == NULL)
		return (-1);
	while (min < max)
	{
		tmp[i] = min++;
		i++;
	}
	*range = tmp;
	return (i);
}
