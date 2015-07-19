/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanlavi <florent-pro@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:44:56 by fsanlavi          #+#    #+#             */
/*   Updated: 2015/07/19 12:28:07 by fsanlavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include "sudoku.h"
#include <stdio.h>

void	display_sudoku(int **sudoku)
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar('0' + sudoku[x][y]);
			if (y != 8)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

int		**read_args(char **argv)
{
	int x;			// ligne
	int y;			// colone
	int **sudoku;	// tableau de int

	sudoku = (int **)malloc(sizeof(int *) * 9);
	x = 0;
	while (x < 9)
	{
		if (ft_strlen(argv[x]) != 9)
			return (NULL);
		sudoku[x] = (int *)malloc(sizeof(int) * 9);
		y = 0;
		while (y < 9)
		{
			if (argv[x][y] == '.')
				sudoku[x][y] = 0;
			else if (argv[x][y] >= '1' && argv[x][y] <= '9')
				sudoku[x][y] = argv[x][y] - '0';
			else
				return (NULL);
			y++;
		}
		x++;
	}
	return (sudoku);
}

int		main(int argc, char **argv)
{
	int **sudoku;

	if (argc == 10)
	{
		sudoku = read_args(&argv[1]);
		printf("read_args()\n");
		if (sudoku == NULL)
		{
			ft_putstr("Erreur\n");
			return (160);
		}
		printf("===== START =====\n");
		display_sudoku(sudoku);
		printf("===== SOLVE =====\n");
		solve(sudoku);
		printf("solve(): done\n");
		display_sudoku(sudoku);
	}
	else
	{
		ft_putstr("Erreur\n");
		return (160);
	}
	return (0);
}
