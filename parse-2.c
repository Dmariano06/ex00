/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozimek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:13:48 by luozimek          #+#    #+#             */
/*   Updated: 2022/09/26 12:38:19 by luozimek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush01.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	cnt_words(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && !is_whitespace(s[i]))
			return (-1);
		if (is_whitespace(s[i]) != ' ' && (i == 0 || is_whitespace(s[i - 1])))
			words++;
		i++;
	}
	return (words);
}

int	**init_res(int **res, char *s, int n, int i)
{
	int	j;
	int	k;
	int	cur;

	j = 0;
	k = 0;
	cur = 0;
	while (s[++i])
	{
		if (is_whitespace(s[i]))
		{
			res[j][k++] = cur;
			cur = 0;
			if (k == n)
			{
				k = 0;
				j++;
			}
			continue ;
		}
		cur = cur * 10 + s[i] - '0';
	}
	res[j][k] = cur;
	return (res);
}

int	**parse(char *s, int *n)
{
	int	**res;

	*n = cnt_words(s);
	if (*n == -1 || *n % 4 || *n / 4 > MAX_N)
		return (NULL);
	*n /= 4;
	res = alloc_grid(4, *n);
	if (!res)
		return (NULL);
	init_res(res, s, *n, -1);
	return (res);
}
