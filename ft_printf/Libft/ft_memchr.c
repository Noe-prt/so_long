/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:27:34 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:36:14 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ss;

	cc = (unsigned char) c;
	ss = (unsigned char *) s;
	while (n > 0)
	{
		if (cc == *ss)
			return ((void *) ss);
		ss++;
		n--;
	}
	return (NULL);
}
/*
#include <unistd.h>

int main(void)
{
    const char str[20] = "ceci est une phrase.";
    char *result;
    result = ft_memchr(str, 'e', 20);
    if (result)
        write(1, result, 20 - (result - str));
    write(1, "\n", 1);
    result = ft_memchr(str, 'a', 10);
    if (result)
        write(1, result, 20 - (result - str));
    else
        write(1, "Character not found\n", 20);
    result = ft_memchr(str, '\0', 20);
    if (result)
        write(1, result, 1);
    write(1, "\n", 1);
    return (0);
}
*/
