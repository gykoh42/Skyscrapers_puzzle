/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojo <yojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:18:54 by gykoh             #+#    #+#             */
/*   Updated: 2023/02/19 21:12:22 by yojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	view_fside(int matrix[4][4], int arg[16]);
int	total_check(int matrix[4][4], int row, int col, int n);

int	find_zero(int map[4][4], int *i, int *j)
{
	*i = 0;
	while (*i <= 3)
	{
		*j = 0;
		while (*j <= 3)
		{
			if (map[*i][*j] == 0)
				return (0);
			*j += 1;
		}
		*i += 1;
	}
	return (1);
}

int	solve(int map[4][4], int arg[16])
{
	int	i;
	int	j;
	int	n;

	if ((find_zero(map, &i, &j)) && (view_fside(map, arg)))
		return (1);
	n = 1;
	while (n <= 4)
	{
		if (total_check(map, i, j, n))
		{
			map[i][j] = n;
			if (solve(map, arg))
				return (1);
			map[i][j] = 0;
		}
		n++;
	}
	return (0);
}
