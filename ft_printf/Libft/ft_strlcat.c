/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:12:25 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:40:09 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}

/*
#include <unistd.h>

int main(void)
{
    char src[6] = "world";
    char dst[11] = "hello";
    write(1, "dst avant appel : ", 19);
    write(1, dst, 6);
    ft_strlcat(dst, src, 4);
    write(1, "\n", 1);
    write(1, "dst apres appel : ", 19);
    write(1, dst, 11);
    write(1, "\n", 1);
    return (0);
}
*/
