/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junahn <junahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:04:00 by gykoh             #+#    #+#             */
/*   Updated: 2023/02/19 21:39:56 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	col_check(int map[4][4], int col, int n)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (map[row][col] == n)
			return (0);
		row++;
	}
	return (1);
}

int	row_check(int map[4][4], int row, int n)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (map[row][col] == n)
			return (0);
		col++;
	}
	return (1);
}

int	total_check(int map[4][4], int row, int col, int n)
{
	if ((col_check(map, col, n) == 1) && (row_check(map, row, n) == 1)
		&& (map[row][col] == 0))
		return (1);
	return (0);
}
