/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:33:14 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/22 18:33:14 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*converter;
	unsigned char	tmp;

	i = -1;
	converter = "0123456789abcdef";
	while (str[++i] != '\0')
	{
		tmp = str[i];
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			ft_putchar('\\');
			ft_putchar(converter[str[i] / 16]);
			ft_putchar(converter[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
	}
}
/*
int		main(void)
{
	char	*string;
	string = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(string);
}
*/
