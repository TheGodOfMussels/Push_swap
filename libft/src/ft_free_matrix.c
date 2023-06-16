/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:24:54 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:24:56 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		matrix[y] = NULL;
		y++;
	}
	free(matrix);
	return (0);
}

char	*ft_free_matrix_xy(char ***matrix, int x, int y)
{
	if (!*matrix)
		return (NULL);
	(void) x;
	while (y--)
	{
		ft_free_null((char **) &((*matrix)[y]));
	}
	free(*matrix);
	return (NULL);
}

/* for free gnl */
char	*ft_free_matrix_nomat(char **matrix, int i)
{
	while (i)
		ft_free_null(&(matrix)[i--]);
	return (NULL);
}
