/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:25:46 by dimolin2          #+#    #+#             */
/*   Updated: 2023/02/28 18:25:47 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_iswhite(str[i]))
		i++;
	return (i);
}

int	ft_ishex(char *str)
{
	unsigned char	i;

	i = 2;
	if (!str || ft_wordlen(str) > 10)
		return (0);
	if (str[0] != '0' || str[1] != 'x')
		return (0);
	while (str[i] != 32 && str[i] != '\n' && str[i] != '\0')
	{
		if (!ft_strchr("0123456789ABCDEFabcdef", str[i]))
			return (0);
		i++;
	}
	return (1);
}
