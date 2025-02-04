/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:46 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/04 11:52:16 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  42
# endif
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

size_t	ft_strlen_c(char *str, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_sub_n_str(char *s, size_t n);
char	*ft_strjoin(char **s1, char **s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
#endif
