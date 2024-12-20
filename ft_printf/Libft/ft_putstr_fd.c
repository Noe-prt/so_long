/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:11 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:13 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
#include <fcntl.h>

int     main(void)
{
        int     fd;

        fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
        ft_putstr_fd("Hello, World!", fd);
        return (0);
}
*/
