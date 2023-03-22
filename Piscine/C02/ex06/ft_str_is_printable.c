/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:41:30 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 21:41:30 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (++str)
		if (*str < 32 || *str > 126)
			return (0);
	return (1);
}
