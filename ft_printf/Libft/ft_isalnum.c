/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:35:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:52:21 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

/*
#include <unistd.h>

int	main(void)
{
	if (ft_isalnum('c'))
		write(1, "1.S\n", 4);
	else
		write(1, "1.F\n", 4);
	if (ft_isalnum('5'))
		write(1, "2.S\n", 4);
	else
		write(1, "2.F\n", 4);
	if (ft_isalnum('?'))
		write(1, "3.F\n", 4);
	else
		write(1, "3.S\n", 4);
}
*/
