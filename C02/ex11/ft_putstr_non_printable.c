/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:49:39 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/03/23 01:42:39 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*converter;
	unsigned char	tmp;

	i = 0;
	converter = "0123456789abcdef";
	while (str[i] != '\0')
	{
		tmp = str[i];
		if (!(tmp >= 32 && tmp <= 127))
		{
			ft_putchar('\\');
			ft_putchar(converter[tmp / 16]);
			ft_putchar(converter[tmp % 16]);
		}
		else
			ft_putchar(tmp);
		i++;
	}
}
