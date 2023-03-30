/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:35:42 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/26 14:48:36 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		c;

	if (!src)
		return (NULL);
	c = -1;
	while (src[++c] != '\0')
		c++;
	new = malloc(sizeof (char) * c + 1);
	if (!new)
		return (NULL);
	c = -1;
	while (src[++c] != '\0')
		new[c] = src[c];
	new[c] = src[c];
	return (new);
}
