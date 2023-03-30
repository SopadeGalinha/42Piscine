/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:43:57 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/26 14:49:55 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*new;
	int	i;

	i = -1;
	if (min >= max)
		return (0);
	new = malloc(sizeof(int *) * (max - min));
	if (!new)
		return (0);
	while (min < max)
		new[++i] = min++;
	return (new);
}
