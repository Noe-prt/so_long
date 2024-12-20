/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:20:39 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:45:43 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <unistd.h>

int main(void)
{
    const char str[20] = "ceci est une phrase.";
    char *result = ft_strrchr(str, 'c');
    write(1, result, 20 - (result - str));
    write(1, "\n", 1);
    result = ft_strrchr(str, '\0');
    write(1, result, 1);
    write(1, "\n", 1);
    
    return (0);
}
*/
