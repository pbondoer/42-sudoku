/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanlavi <florent-pro@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 21:36:11 by fsanlavi          #+#    #+#             */
/*   Updated: 2015/07/19 18:50:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_square(int i)
{
	return (i - i % 3);
}

int		is_valid(int **sudoku, int row, int col, int val)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		if (sudoku[i][col] == val || sudoku[row][i] == val)
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (sudoku[get_square(row) + i][get_square(col) + j] == val)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		solve(int **sudoku, int val)
{
	int x;
	int y;
	int i;

	x = val / 9;
	y = val % 9;
	i = 1;
	if (val >= 81)
		return (1);
	if (sudoku[x][y] != 0)
		return (solve(sudoku, val + 1));
	while (i < 10)
	{
		if (is_valid(sudoku, x, y, i))
		{
			sudoku[x][y] = i;
			if (solve(sudoku, val + 1))
				return (1);
			else
				sudoku[x][y] = 0;
		}
		i++;
	}
	return (0);
}
