/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:47 by rorollin          #+#    #+#             */
/*   Updated: 2025/01/29 19:14:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					counter;
	const unsigned char		*p_source;
	unsigned char			*p_dest;

	counter = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	p_source = src;
	p_dest = dest;
	while (counter < n)
	{
		p_dest[counter] = p_source[counter];
		counter++;
	}
	return (p_dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_bytes;
	size_t	i;

	result = NULL;
	total_bytes = nmemb * size;
	i = 0;
	if (total_bytes > INT_MAX)
		return (result);
	result = malloc(total_bytes);
	if (result == NULL)
		return (NULL);
	while (i < total_bytes)
		((char *) result)[i++] = 0;
	return (result);
}

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_n_substr(char *s, size_t n)
{
	char	*new_string;
	size_t	max_mem;

	new_string = NULL;
	if (s == NULL || s[0] == '\0')
		return (NULL);
	max_mem = ft_strlen(s, '\n');
	if (max_mem == 0 || n == 0)
		return (NULL);
	if (max_mem > n)
		max_mem = n;
	new_string = ft_calloc((max_mem + 1), sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memcpy(new_string, s, max_mem);
	return (new_string);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*new_string;
	size_t	len_s1;
	size_t	len_s2;

	if (*s1 == NULL && *s2 == NULL)
		return (NULL);
	if (*s1 == NULL)
		return (*s2);
	if (*s2 == NULL)
		return (*s1);
	len_s1 = ft_strlen(*s1, '\n');
	len_s2 = ft_strlen(*s2, '\n');
	new_string = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (new_string == NULL)
	{
		free(*s1);
		free(*s2);
		return (NULL);
	}
	ft_memcpy(new_string, *s1, len_s1);
	ft_memcpy(&new_string[len_s1], *s2, len_s2);
	free(*s1);
	free(*s2);
	return (new_string);
}
