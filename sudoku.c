/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanlavi <florent-pro@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 21:36:11 by fsanlavi          #+#    #+#             */
/*   Updated: 2015/07/19 12:27:24 by fsanlavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_lib.h"

void	display_sudoku(int **sudoku);

int		get_square(int i)
{
	return ((i / 3) * 3);
}

int		*get_possible(int **sudoku, int line, int col)
{
	int *possible;
	int x;
	int y;
		
	possible = (int *)malloc(sizeof(int) * 9);
	x = 0;
	while (x < 9)
	{
		possible[x] = 1;
		x++;
	}
	x = 0;
	while (x < 9)
	{
		if (sudoku[x][col] != 0)
			possible[sudoku[x][col] - 1] = 0;
		x++;
	}
	y = 0;
	while (y < 9)
	{
		if (sudoku[line][y] != 0)
			possible[sudoku[line][y] - 1] = 0;
		y++;
	}
	x = 0;
	y = 0;
	
	while (x < 3)
	{
		while (y < 3)
		{
			if (sudoku[get_square(line) + x][get_square(col) + y] != 0)
				possible[sudoku[get_square(line) + x][get_square(col) + y] - 1] = 0;
			y++;
		}
		x++;
	}
	
	return (possible);
}

int		solve_cell(int **sudoku, int line, int col)
{
	int *possible;
	int i;
	int c;
	int l;

	//if(sudoku[line][col] != 0)
	//	return (0);

	possible = get_possible(sudoku, line, col);
	i = 0;
	c = 0;
	while (i < 9)
	{
		if (possible[i] == 1)
		{
			l = i + 1;
			c++;
		}
		i++;
	}
	free(possible);
	if (c == 1)
	{
		printf("changed cell %d;%d from %d to %d\n", line, col, sudoku[line][col], l);
		sudoku[line][col] = l;
		return (1);
	}
	return (0);
}

void	solve(int **sudoku)
{
	int x;
	int y;
	int c;
	
	c = 1;
	while (c > 0)
	{
		c = 0;
		x = 0;
		while (x < 9)
		{
			y = 0;
			while (y < 9)
			{
				c += solve_cell(sudoku, x, y);
				y++;
			}
			x++;
		}
		printf(" > total changed %d\n", c);
		//display_sudoku(sudoku);
		//ft_putstr("=================\n");
	}
}
