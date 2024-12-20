/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:11:52 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:50 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isprint('c'))
		write(1, "1.S\n", 4);
	else
		write(1, "1.F\n", 4);
	if (ft_isprint('5'))
		write(1, "2.S\n", 4);
	else
		write(1, "2.F\n", 4);
	if (ft_isprint(200))
		write(1, "3.F\n", 4);
	else
		write(1, "3.S\n", 4);
}
*/
