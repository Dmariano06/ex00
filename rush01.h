/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:34:41 by luozimek          #+#    #+#             */
/*   Updated: 2022/09/26 12:38:43 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# define MAX_N 9
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		**parse(char *s, int *n);
int		**free_grid(int **res, int n);
int		**alloc_grid(int n, int m);
int		ft_min(int a, int b);
void	ft_swap(int *a, int *b);
int		ft_error(int **grid, int **sky, int n);
int		check(int ***s_g, int x, int y, int size);
int		check_row(int *row, int size);
int		check_col(int **grid, int col_index, int size);
int		check_row_reverse(int *row, int target, int size);
int		check_col_reverse(int **grid, int col_index, int target, int size);
int		check_doublon_row(int *row, int size);
int		check_doublon_col(int **grid, int col_index, int size);
#endif
