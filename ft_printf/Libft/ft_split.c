/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:01 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:06 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	*split_word(int min, int max, const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char *) * (max - min + 1));
	if (min >= max)
		return (NULL);
	while (min < max)
	{
		dest[i] = s[min];
		i++;
		min++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		split_index;
	char	**split;

	i = 0;
	split_index = 0;
	j = 0;
	split = malloc(sizeof(char *) * ((count_words(s, c) + 1)));
	while (s[i])
	{
		if (s[i] != c)
		{
			if (split_index == 0 || s[i - 1] == c)
				j = i;
			while (s[i] && s[i] != c)
				i++;
			split[split_index++] = split_word(j, i, s);
		}
		else
			i++;
	}
	split[split_index] = 0;
	return (split);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	char *str;
	char **split;

	i = 0;
	str = "Je suis une phrase.";
	split = ft_split(str, '');
	while (i < 4)
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}
*/
