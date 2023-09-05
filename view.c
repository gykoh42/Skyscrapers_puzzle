/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojo <yojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:11:30 by gykoh             #+#    #+#             */
/*   Updated: 2023/02/19 21:49:20 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	view_up(int map[4][4], int col, int col_sec)
{
	int	i;
	int	flag;
	int	max;

	max = map[0][col];
	i = 1;
	flag = 1;
	while (i <= 3)
	{
		if (max < map[i][col])
		{
			max = map[i][col];
			flag++;
		}
		i++;
	}
	if (flag == col_sec)
		return (1);
	return (0);
}

int	view_down(int map[4][4], int col, int col_sec)
{
	int	i;
	int	flag;
	int	max;

	max = map[3][col];
	i = 2;
	flag = 1;
	while (i >= 0)
	{
		if (max < map[i][col])
		{
			max = map[i][col];
			flag++;
		}
		i--;
	}
	if (flag == col_sec)
		return (1);
	return (0);
}

int	view_left(int map[4][4], int row, int row_sec)
{
	int	j;
	int	flag;
	int	max;

	max = map[row][0];
	j = 1;
	flag = 1;
	while (j <= 3)
	{
		if (max < map[row][j])
		{
			max = map[row][j];
			flag++;
		}
		j++;
	}
	if (flag == row_sec)
		return (1);
	return (0);
}

int	view_right(int map[4][4], int row, int row_sec)
{
	int	j;
	int	flag;
	int	max;

	max = map[row][3];
	j = 2;
	flag = 1;
	while (j >= 0)
	{
		if (max < map[row][j])
		{
			max = map[row][j];
			flag++;
		}
		j--;
	}
	if (flag == row_sec)
		return (1);
	return (0);
}

int	view_fside(int map[4][4], int arg[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (0 <= i && i <= 3)
			if (view_up(map, i, arg[i]) != 1)
				return (0);
		if (4 <= i && i <= 7)
			if (view_down(map, i - 4, arg[i]) != 1)
				return (0);
		if (8 <= i && i <= 11)
			if (view_left(map, i - 8, arg[i]) != 1)
				return (0);
		if (12 <= i && i <= 15)
			if (view_right(map, i - 12, arg[i]) != 1)
				return (0);
		i++;
	}
	return (1);
}
