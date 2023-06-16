/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:01:19 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/20 19:01:20 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countmatrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**ft_dup_matrix(char **matrix)
{
	int		y;
	int		x;
	char	**result;

	result = (char **)malloc(sizeof(char *) * ft_countmatrix(matrix) + 1);
	if (!result)
		return (NULL);
	y = 0;
	while (matrix[y])
	{
		result[y] = (char *)malloc(sizeof(char) * ft_strlen(matrix[y]) + 1);
		if (!result[y])
			return (NULL);
		x = 0;
		while (matrix[y][x])
		{
			result[y][x] = matrix[y][x];
			x++;
		}
		result[y][x] = '\0';
		y++;
	}
	result[y] = NULL;
	return (result);
}
