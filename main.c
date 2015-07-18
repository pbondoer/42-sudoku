/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanlavi <florent-pro@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:44:56 by fsanlavi          #+#    #+#             */
/*   Updated: 2015/07/18 19:44:24 by fsanlavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	display_sudoku(int *sudoku)
{
	int i;

	i = 0;
	while (i < 81)
	{
		ft_putchar('0' + sudoku[i]);
		if (i % 9 == 8)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}

int		*read_args(char **argv)
{
	int i;			// ligne
	int x;			// colone
	int *sudoku;	// tableau de int

	sudoku = (int *)malloc(sizeof(int) * 81);
	i = 0;
	while (i < 9)
	{
		x = 0;
		if (ft_strlen(argv[i]) != 9)
			return (NULL);
		while (x < 9)
		{
			if (argv[i][x] == '.')
				sudoku[i * 9 + x] = 0;
			else if (argv[i][x] >= '1' && argv[i][x] <= '9')
				sudoku[i * 9 + x] = argv[i][x] - '0';
			else
				return (NULL);
			x++;
		}
		i++;
	}
	return (sudoku);
}

int		main(int argc, char **argv)
{
	int *sudoku;

	if (argc == 10)
	{
		sudoku = read_args(&argv[1]);
		if (sudoku == NULL)
		{
			ft_putstr("Erreur\n");
			return (160);
		}
		display_sudoku(sudoku);
		free(sudoku);
	}
	else
	{
		ft_putstr("Erreur\n");
		return (160);
	}
	return (0);
}
