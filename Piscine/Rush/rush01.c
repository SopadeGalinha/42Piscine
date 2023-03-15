/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:52:26 by jhgoncal          #+#    #+#             */
/*   Updated: 2023/02/18 16:52:26 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*1*/int	ft_countalpha(char *s, char c); // CHECK THE SIZE OF THE GIVEN ARGUMENT
/*2*/char	**ft_deftab(char *src, int trigger); // FREE THE MEMORY ALLOCATED
/*3*/char	**ft_filltab(char **columns, char *src); // FILL THE TABLE WITH THE GIVEN ARGUMENT
/*4*/void	ft_free(char **matrizfinal, char **rows_cols); //FREE THE ALLOCATED MEMORY
/*5*/void	ft_do_the_things(char **rows_cols, char **matriz); //DO THE THINGS
/*6*/void	ft_fill_four(char **row_cols, char **matrizfinal); //FILL THE TABLE WITH THE NUMBER FOUR
/*7*/int	ft_verify_row(char **matrizfinal, int row, char contains); // RETURNS 1 IF THE VALUE IS IN THE ROW
/*8*/int	ft_verify_column(char **matrizfinal, int column, char contains); // RETURNS 1 IF THE VALUE IS IN THE COLUMN
/*9*/void	ft_fill_easyones_horizontal_part1(char **rows_cols, char **matriz); //PUT 123 HORIZONTAL
/*10*/void	ft_fill_easyones_vertical_part1(char **rows_cols, char **matriz); //PUT 123 VERTICAL
/*11*/void	ft_fill_easyones_vertical_part2(char **rows_cols, char **matriz);
/*12*/void	ft_fill_easyones_horizontal_part2(char **rows_cols, char **matriz);
/*13*/void	ft_putthree_part2(char **rows_cols, char **matriz);
/*14*/void	ft_putthree_part1(char **rows_cols, char **matriz);




char	**ft_filltab(char **columns, char *src)
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
			columns[pos][i] = *src++;
		}
		columns[pos][i] = '\0';
	}
	columns[pos] = '\0';
	return (columns);
}
char	**ft_deftab(char *src, int trigger)
{
	int		pos;
	char	**columns;

	columns = malloc(sizeof(char *) * 4);
	if (columns == NULL)
		return NULL;
	pos = -1;
	while (++pos < 4)
	{
		columns[pos] = malloc(sizeof(char) * 4);
		if (columns[pos] == NULL)
		{
			pos = -1;
			while (columns[pos])
				free(columns[pos]);
			free(columns);
			return (NULL);
		}
	}
	if (trigger == 1)
		return (ft_filltab(columns, "0000000000000000"));
	return (ft_filltab(columns, src));
}
int		ft_countalpha(char *s, char c)
{
	int	i;

	i = 0;
	while (*s++)
	{
		if (*s == c)
			continue ;
		else
			i++;
	}
	return (i);
}
void	ft_free(char **matrizfinal, char **rows_cols)
{
	int	i;

	i = -1;
	while (matrizfinal[++i])
		free(matrizfinal[i]);
	free(matrizfinal);
	i = -1;
	while (rows_cols[++i])
		free(rows_cols[i]);
	free(rows_cols);
}
void	ft_fill_four(char **row_cols, char **matrizfinal)
{
	int	column;
	int	row;

	row = -1;
	column = -1;
	while (row_cols[0][++column])
	{
		if (row_cols[0][column] == '1')		//VERIFY COLUMNS
			matrizfinal[0][column] = '4';
		if (row_cols[1][column] == '1')		//VERIFY COLUMNS
			matrizfinal[3][column] = '4';
		if (row_cols[2][column] == '1')		//VERIFY ROWS
			matrizfinal[column][0] = '4';
		if (row_cols[3][column] == '1')		//VERIFY ROWS
			matrizfinal[column][3] = '4';
	}
	if (!ft_verify_column(matrizfinal, 1, '4') && !ft_verify_row(matrizfinal, 1, '4') && row_cols[2][1] == '2' && row_cols[0][1] == '2')
			matrizfinal[1][1] = '4';
	if (!ft_verify_column(matrizfinal, 2, '4') && !ft_verify_row(matrizfinal, 1, '4') && row_cols[3][1] == '2' && row_cols[0][2] == '2')
			matrizfinal[1][2] = '4';
	if (!ft_verify_column(matrizfinal, 1, '4') && !ft_verify_row(matrizfinal, 2, '4') &&	row_cols[1][1] == '2' && row_cols[2][2] == '2')
			matrizfinal[2][1] = '4';
	if (!ft_verify_column(matrizfinal, 2, '4') && !ft_verify_row(matrizfinal, 2, '4') &&	row_cols[1][2] == '2' && row_cols[3][2] == '2')
			matrizfinal[2][2] = '4';
}
int		ft_verify_column(char **matrizfinal, int column, char contains)
{
	int	i;

	i = -1;

	while (++i < 4)
		if (matrizfinal[i][column] == contains)
			return (1);
	return (0);
}
int		ft_verify_row(char **matrizfinal, int row, char contains)
{
	int	i;

	i = -1;

	while (++i < 4)
		if (matrizfinal[row][i] == contains)
			return (1);
	return (0);
}
void	ft_fill_easyones_horizontal_part1(char **rows_cols, char **matriz)
{
	int	i;
	int	rows;
	int fill;

	i = 0;
	fill = 4;
	rows = -1;
	while (matriz[++rows])
		if (matriz[rows][0] == '4' && rows_cols[3][rows] == '4')
			while (fill > 1)
				matriz[rows][++i] = --fill + '0';
	i = -1;
	fill = 0;
	while (--rows >= 0)
		if (matriz[rows][3] == '4' && rows_cols[2][rows] == '4')
			while (++fill < 4)
				matriz[rows][++i] = fill +'0';
}
void	ft_fill_easyones_vertical_part1(char **rows_cols, char **matriz)
{
	int	i;
	int	column;
	int	row;
	int	fill;

	i = 4;
	fill = 0;
	row = 0;
	column = -1;
	while (matriz[0][++column])
		if (matriz[0][column] == '4' && rows_cols[1][column] == '4')
			while (--i > 0)
				matriz[i][column] = ++fill + '0';
	
	i = -1;
	fill = 0;
	while (matriz[3][--column])
	if (matriz[3][column] == '4' && rows_cols[0][column] == '4')
			while (++i < 4)
				matriz[i][column] = ++fill + '0';
}
void	ft_putthree_part1(char **rows_cols, char **matriz)
{
	int	i;

	i = -1;
	while (rows_cols[0][++i])
	{
		if (rows_cols[0][i] == '3')
		{
			if (ft_verify_column(matriz, i, '1') && matriz[0][i] == '0')
				matriz[0][i] = '2';
			else if (ft_verify_column(matriz, i, '2') && matriz[0][i] == '0')
				matriz[0][i] = '1';
		}
		if (rows_cols[1][i] == '3')
		{
			if (ft_verify_column(matriz, i, '1') && matriz[3][i] == '0')
				matriz[3][i] = '2';
			else if (ft_verify_column(matriz, i, '2') && matriz[3][i] == '0')
				matriz[3][i] = '1';
		}
	}
}
void	ft_putthree_part2(char **rows_cols, char **matriz)
{
	int	i;

	i = -1;
	while (rows_cols[2][++i])
	{
		if (rows_cols[2][i] == '3')
		{
			if (ft_verify_row(matriz, i, '1') && matriz[i][0] == '0')
				matriz[i][0] = '2';
			else if (ft_verify_row(matriz, i, '2') && matriz[i][0] == '0')
				matriz[i][0] = '1';
		}
		if (rows_cols[3][i] == '3')
		{
			if (ft_verify_row(matriz, i, '1') && matriz[i][3] == '0')
				matriz[i][3] = '2';
			else if (ft_verify_row(matriz, i, '2') && matriz[i][3] == '0')
				matriz[i][3] = '1';
		}
	}
}
void	ft_fill_easyones_horizontal_part2(char **rows_cols, char **matriz)
{
	int	rows;
	int	i;

	rows = -1;
	while (matriz[++rows])
	{
		if ((matriz[rows][0] == '0' || matriz[rows][1] == '0') && matriz[rows][2] == '3' && matriz[rows][3] == '4')
		{
			matriz[rows][0] = '2';
			matriz[rows][1] = '1';
		}
		if ((matriz[rows][3] == '0' || matriz[rows][2] == '0') && matriz[rows][0] == '4' && matriz[rows][1] == '3')
		{
			matriz[rows][2] = '1';
			matriz[rows][3] = '2';
		}
	}
}
void	ft_fill_easyones_vertical_part2(char **rows_cols, char **matriz)
{
	int	column;
	int	i;

	column = -1;
	while (matriz[0][++column])
	{
		if (matriz[0][column] == '0' || matriz[1][column] == '0')
			if (matriz[3][column] == '4' && matriz[2][column] == '3')
			{
				matriz[0][column] = '2';
				matriz[1][column] = '1';
			}
		if (matriz[3][column] == '0' || matriz[2][column] == '0')
			if (matriz[0][column] == '4' && matriz[1][column] == '3')
			{
				matriz[2][column] = '1';
				matriz[3][column] = '2';
			}
	}
}

int		ft_rowcounter(char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[++k])
		if (s[k] == c)
			i++;
	return (i);
}

int		ft_columncounter(char **matriz, int column, char c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (++k < 4)
		if (matriz[k][column] == c)
			i++;
	return (i);
}

void	ft_fill_lastpos(char **matriz)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	while (matriz[++i])
	{
		k = -1;
		if (ft_verify_row(matriz, i, '0') && ft_rowcounter(matriz[i], '0') == 1)
		{
			if (!ft_verify_row(matriz, i, '3') && !ft_verify_column(matriz, i, '3'))
				while (matriz[i][++k])
					if (matriz[i][k] == '0')
						matriz[i][k] = '3';
			else if (!ft_verify_row(matriz, i, '2') && !ft_verify_column(matriz, i, '2'))
				while (matriz[i][++k])
					if (matriz[i][k] == '0')
						matriz[i][k] = '2';
			else
				while (matriz[i][++k])
					if (matriz[i][k] == '0')
						matriz[i][k] = '1';
		}
	}
}

void	ft_do_the_things(char **rows_cols, char **matriz)
{
	int i = -1;
	ft_fill_four(rows_cols, matriz);
	ft_fill_easyones_vertical_part1(rows_cols, matriz);
	ft_fill_easyones_horizontal_part1(rows_cols, matriz);
	ft_fill_easyones_vertical_part2(rows_cols, matriz);
	ft_fill_easyones_horizontal_part2(rows_cols, matriz);
	ft_putthree_part1(rows_cols, matriz);
	ft_putthree_part2(rows_cols, matriz);
	ft_fill_lastpos(matriz);
	if (ft_rowcounter(rows_cols[1], '3') == 2)
	{
		while (matriz[3][++i])
		{
			if (matriz[3][i] == '0')
			{
				if (rows_cols[1][i] != '3')
					matriz[3][i] = '3';
			}
		}
	ft_putthree_part1(rows_cols, matriz);
	ft_putthree_part2(rows_cols, matriz);
	ft_fill_lastpos(matriz);
	}
}

#include <string.h>
int	main(int ac, char **av)
{
	char	**matrizfinal;
	int		i;

	i = -1;
	if (ft_countalpha(av[1], ' ') != 16)
		return (write(1, "Error\n", 6));
	av = ft_deftab(av[1], 0);
	matrizfinal = ft_deftab(av[1], 1);
	ft_do_the_things(av, matrizfinal);

	// PRINT
	while (matrizfinal[++i])
		printf("%s\n", matrizfinal[i]);
	ft_free(matrizfinal, av);
	return (0);
}
