/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:38:00 by npareti           #+#    #+#             */
/*   Updated: 2024/12/20 08:41:55 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_get_line(char	*stash);
char	*ft_new_stash(char *stash);
char	*ft_fill_stash(int fd, char *stash);

#endif
