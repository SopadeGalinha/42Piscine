/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:24:07 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/18 19:13:07 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	con;

	con = 0;
	while (src[con] != '\0')
	{
		dest[con] = src[con];
		con++;
	}
	dest[con] = src[con];
	return (dest);
}
