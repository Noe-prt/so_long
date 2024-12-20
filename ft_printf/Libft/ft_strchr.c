/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:00:04 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:43:57 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (cc == *s)
		return ((char *) s);
	return (NULL);
}
/*
#include <unistd.h>

int main(void)
{
    const char str[20] = "ceci est une phrase.";
    char *result = ft_strchr(str, 'c');
    write(1, result, 20 - (result - str));
    write(1, "\n", 1);
    result = ft_strchr(str, '\0');
    write(1, result, 1);
    write(1, "\n", 1);
    
    return (0);
}
*/
