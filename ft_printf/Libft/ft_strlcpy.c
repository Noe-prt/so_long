/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:27:59 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:42:20 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}
/*
#include <unistd.h>

int main(void)
{
    char src[6] = "hello";
    char dst[6] = "......";
    write(1, "dst avant appel : ", 19);
    write(1, dst, 6);
    ft_strlcpy(dst, src, 4);
    write(1, "\n", 1);
    write(1, "dst apres appel : ", 19);
    write(1, dst, 6);
    write(1, "\n", 1);
    return (0);
}
*/
