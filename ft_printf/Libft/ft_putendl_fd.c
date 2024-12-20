/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:23 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:27 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>

int     main(void)
{
        int     fd;

        fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
        ft_putendl_fd("Hello, World!", fd);
        return (0);
}
*/
