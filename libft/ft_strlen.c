/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:24:30 by smercado          #+#    #+#             */
/*   Updated: 2024/09/04 08:20:16 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen( char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
/*
int	main(void)
{
	char * str = "hola que tal";
	int ret;

	ret = ft_strlen(str);
	printf("%d\n", ret);
	return (0);
}*/
