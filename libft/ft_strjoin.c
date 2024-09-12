/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:33:16 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 09:11:33 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* s2 se anade en s1. 
return> la nueva str o null si falla malloc. 
*/

static int	ft_lenconc(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strlen(s2) + 1);
	else if (s1 && !s2)
		return (ft_strlen(s1) + 1);
	else
		return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * ft_lenconc(s1, s2));
	if (!str)
		return (ft_free(&s1), NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[j + i] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	return (ft_free(&s1), str);
}
/*
int main()
{
    // Cadenas de prueba
     char *s1 = "Hello, ";
     char *s2 = "World!";

    // Llamar a ft_strjoin
    char *joined_str = ft_strjoin(s1, s2);

    // Imprimir el resultado
    if (joined_str)
    {
        printf("Joined string: %s\n", joined_str);
        //free(joined_str);  // Liberar memoria asignada
    }
    else
    {
        printf("Failed to allocate memory for joined string.\n");
    }

    return 0;
}
*/
