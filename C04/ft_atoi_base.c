/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:43:19 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/27 23:09:57 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
			if (base[j++] == base[i])
				return (0);
		if (base[i] == '-' || base[i] == '+'
			|| base[i] <= 15 || base[i] == ' ' || base[i] == 127)
			return (0);
		++i;
	}
	return (i);
}

int	findchar(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (c == str[i])
			return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				sign;
	int				result;
	int				offset;
	unsigned int	basen;

	result = 0;
	sign = 1;
	basen = check_base(base);
	if (basen < 2)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '\0')
	{
		offset = findchar(*str, base);
		if (offset < 0)
			break ;
		result = result * basen + sign * offset;
		str++;
	}
	return (result);
}
