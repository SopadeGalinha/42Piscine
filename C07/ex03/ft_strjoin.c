/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jhogonca@student.42porto.com <jhogonca    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:43:50 by jhogonca          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:04 by  jhogonca@s      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_fcknorm(char *new, char **strs, int size, char *sep)
{
	int	len;
	int	c;
	int	s;

	s = -1;
	len = -1;
	while (strs[++len])
	{
		c = -1;
		while (strs[len][++c])
			new[++s] = strs[len][c];
		c = -1;
		while (sep[++c] && len < (size - 1))
			new[++s] = sep[c];
	}
	return (new);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		s;
	int		len;
	char	*new;
	int		c;

	if (size == 0)
	{
		new = malloc(1);
		if (new == NULL)
			return (NULL);
		new[1] = '\0';
		return (new);
	}
	s = -1;
	len = 0;
	while (strs[++s])
		len += ft_strlen(strs[s]);
	len += 1 + (ft_strlen(sep) * (size -1));
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	new = ft_fcknorm(new, strs, size, sep);
	new[len] = '\0';
	return (new);
}
