/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:58:13 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:58:16 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s);
	dest = malloc(length * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

char to_upper(unsigned int index, char c)
{
}

int	main(void)
{
	char *result = ft_strmapi("hello", to_upper);
	printf("%s\n", result);
	return (0);
}
*/
