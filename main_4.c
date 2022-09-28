/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:40:59 by luozimek          #+#    #+#             */
/*   Updated: 2022/09/26 12:38:11 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	print_solution(int **grid, int n, int m)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			c = '0' + grid[i][j];
			write(1, &c, 1);
			if (j < m - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (42);
}

int	check_doublon_row(int *row, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (row[i] == row[j] && row[i] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_doublon_col(int **grid, int col_index, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (grid[col_index][i] == grid[col_index][j]
				&& grid[col_index][i] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	dfs(int ***s_g, int n, int i, int j)
{
	int	k;
	int	**grid;

	grid = s_g[1];
	k = 0;
	if (i == n)
		return (print_solution(s_g[1], n, n));
	while (++k <= n)
	{
		grid[i][j] = k;
		if (check(s_g, i, j, n))
			if (dfs(s_g, n, i + (j == n - 1), (j + 1) % n))
				return (1);
	}
	grid[i][j] = 0;
	return (0);
}

int	solve(int **sky, int n)
{
	int	**grid;
	int	**s_g[2];

	grid = alloc_grid(n, n);
	s_g[0] = sky;
	s_g[1] = grid;
	if (!grid)
		return (0);
	if (!dfs(s_g, n, 0, 0))
		write(2, "Error\n", 7);
	free_grid(grid, n);
	return (0);
}

int	main(int ac, char **av)
{
	int	**sky;
	int	n;

	if (ac != 2)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	sky = parse(av[1], &n);
	if (!sky)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	solve(sky, n);
	free_grid(sky, n);
	return (0);
}
