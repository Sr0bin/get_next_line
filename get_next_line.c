/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/02/04 11:37:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	contain_nl(char *str)
{
	size_t	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (str[counter] != '\0')
	{
		if (str[counter] == '\n')
			return (1);
		counter++;
	}
	return (0);
}

static void	*reset_buffer(char *buffer, size_t n)
{
	size_t	counter;

	counter = 0;
	ft_memcpy(buffer, &buffer[n], BUFFER_SIZE + 1 - n);
	while (counter <= n)
	{
		buffer[BUFFER_SIZE - counter] = 0;
		counter++;
	}
	return (NULL);
}

static void	*clean_exit(char **str1, char **str2, char buffer[BUFFER_SIZE + 1])
{
	free(*str1);
	free(*str2);
	return (reset_buffer(buffer, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*output;
	char		*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (reset_buffer(buffer, BUFFER_SIZE));
	bytes_read = 1;
	output = ft_sub_n_str(buffer, ft_strlen(buffer, '\n'));
	reset_buffer(buffer, ft_strlen(buffer, '\n'));
	while (bytes_read > 0 && !contain_nl(output))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (clean_exit(&output, &temp, (char *) buffer));
		temp = ft_sub_n_str(buffer, bytes_read);
		if (temp == NULL && ft_strlen(buffer, '\n') != 0)
			return (clean_exit(&output, &temp, (char *) buffer));
		reset_buffer(buffer, ft_strlen(temp, '\n'));
		output = ft_strjoin(&output, &temp);
	}
	return (output);
}
