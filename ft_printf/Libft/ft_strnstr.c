/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:28:13 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/06 14:25:50 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	i = 0;
	j = 0;
	len_little = ft_strlen((char *) little);
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (j == len_little - 1)
				return ((char *) &big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char* largestring = "lorem ipsum dolor sit amet";
	const char *smallstring = "ipsum";
	char *ptr;
	ptr = ft_strnstr(largestring, smallstring, 11);
	printf("%s", ptr);
	return (0);
}
*/