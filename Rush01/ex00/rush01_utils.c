/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:30:07 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/19 21:30:07 by jhogonca         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	while(src[++i] && n > 0)
	{
		if (src[i] == ' ')
			continue ;
		dest[++c] = src[i];
		n--;
	}
	dest[c + 1] = '\0';
	return (dest);
}

void	ft_print_table(int board[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(board[i][j] + '0');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
