/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:20:21 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:31:01 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (char *) dst;
	tmp_src = (char *) src;
	i = 0;
	if (tmp_dst > tmp_src)
	{
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	}
	else
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <unistd.h>

int main(void)
{
    char buffer[20] = "12345ABCDE";
    char *src = buffer;
    char *dst = buffer + 3;

    write(1, "Avant ft_memmove:\n", 18);
    write(1, buffer, 10);
    write(1, "\n", 1);

    ft_memmove(dst, src, 6);

    write(1, "Après ft_memmove:\n", 18);
    write(1, buffer, 10);
    write(1, "\n", 1);

    return (0);
}
*/
