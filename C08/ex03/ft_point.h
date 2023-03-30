/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jhogonca@student.42porto.com <jhogonca    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:00:58 by  jhogonca@s       #+#    #+#             */
/*   Updated: 2023/03/30 18:01:53 by  jhogonca@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_POINT_H__

# define __FT_POINT_H__

typedef struct s_point
{
	int x;
	int y;
}	t_point;

// pout le test
void	ft_putchar(char);
void	ft_putnbr(int);
#endif