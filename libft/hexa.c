/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:25:57 by smercado          #+#    #+#             */
/*   Updated: 2024/07/08 08:03:51 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexamayus(unsigned int nh, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nh < 16)
		ft_putcharplus(base[nh], count);
	else
	{
		ft_puthexamayus(nh / 16, count);
		ft_putcharplus((int)base[nh % 16], count);
	}
}

void	ft_puthexaminus(unsigned int nh, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nh < 16)
		ft_putcharplus(base[nh], count);
	else
	{
		ft_puthexaminus(nh / 16, count);
		ft_putcharplus((int)base[nh % 16], count);
	}
}
