/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:31:09 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:31:10 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnset(char const *set, char c)
{
	size_t	k;

	k = 0;
	while (set[k] != '\0')
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	k;
	size_t	len_s1;

	k = 0;
	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1) - 1;
	while (ft_isnset(set, s1[k]))
		k++;
	while (ft_isnset(set, s1[len_s1]))
		len_s1--;
	trimmed = ft_substr(s1, k, len_s1 - k + 1);
	if (trimmed == NULL)
		return (NULL);
	return (trimmed);
}
