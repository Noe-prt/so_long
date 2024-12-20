/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:58:48 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:58:51 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void to_uppercase(unsigned int index, char *c)
{
    if (*c >= 'a' && *c <= 'z' && index % 2 == 0)
        *c -= 32;
}

int	main(void)
{
	char str[] = "hello world";
	printf("Avant appel: %s\n", str);
	ft_striteri(str, to_uppercase);
	printf("Apres : %s\n", str);
	return (0);	
}
*/
