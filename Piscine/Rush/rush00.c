/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:53:45 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/15 20:53:45 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:49:39 by jhgoncal          #+#    #+#             */
/*   Updated: 2021/09/23 20:25:37 by jhgoncal         ###   ########.fr       */
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
int		main(void)
{
	char	*string;
	string = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(string);
}
