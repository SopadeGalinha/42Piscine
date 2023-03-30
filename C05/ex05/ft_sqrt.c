/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:00:21 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/26 00:53:01 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	index;
	long	n;

	n = nb;
	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	index = 2;
	if (n >= 2)
	{
		while (index * index <= n)
		{
			if (index * index == n)
				return (index);
			index++;
		}
	}
	return (0);
}
