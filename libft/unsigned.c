/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:26:35 by smercado          #+#    #+#             */
/*   Updated: 2024/07/09 08:34:26 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*place_str(char *str, unsigned int i, unsigned int n)
{
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

void	ft_putunsigned(unsigned int n, int *count)
{
	unsigned int	size;
	char			*str;
	unsigned int	i;	

	i = 0;
	if (!n)
	{
		ft_putstrplus("0", count);
		return ;
	}
	size = n;
	while (size > 0)
	{
		size = size / 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	ft_putstrplus((place_str(str, i, n)), count);
	free(str);
}
