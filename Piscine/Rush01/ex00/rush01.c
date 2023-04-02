
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

char	**ft_filltab(char **tab, char *src)
{
	int	pos;
	int	i;

	pos = -1;
	while (++pos < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (*src == ' ')
				src++;
			tab[pos][i] = *src++;
		}
		tab[pos][i] = '\0';
	}
	tab[pos] = '\0';
	return (tab);
}

char	**ft_malloc(char *src)
{
	int		pos;
	char	**tab;

	tab = malloc(sizeof(char *) * 4);
	if (tab == NULL)
		return NULL;
	pos = -1;
	while (++pos < 4)
	{
		tab[pos] = malloc(sizeof(char) * 4);
		if (tab[pos] == NULL)
			return (NULL);
	}
	return (ft_filltab(tab, src));
}

int	ft_init(int board[4][4], char *av)
{
	int		c;
	int		i;
	
	i = -1;
	if (ft_strlen(av) != 31)
		return (0);
	while (av[++i])
	{
		if (i % 2 == 0)
		{
			if (!(av[i] >= '1' && av[i] <= '4'))
				return (0);
			if (av[i] == ' ')
				return (0);
		}	
	}
	i = -1;
	while (++i < 4)
	{
	  c = -1;
	  while (++c < 4)
	    board[i][c] = 0;
	}
	return (1);
}

int main(int ac, char **av)
{
	int		board[4][4];
	int		i;
	char	dest[16];
	char	**tab;
	int		trigger;

	if (ac < 2)
		return (0);
	i = -1;
	trigger = 0;
	ft_strncpy(dest, av[1], 16);
	if (ft_init(board, av[1]) == 0)
		exit(write(1, "Error\n", 6));
	tab = ft_malloc(dest);
	ft_combinations(board, 0, 0, tab, &trigger);
	if (trigger == 0)
		return (write(1, "Error\n", 6));
	i = 4;
	while (--i >= 0)
		if (tab[i])
			free(tab[i]);
	if (tab)
		free(tab);
	return (0);
}
