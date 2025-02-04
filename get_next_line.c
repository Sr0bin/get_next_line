/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:43 by rorollin          #+#    #+#             */
/*   Updated: 2025/01/30 11:51:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	contain_nl(char *str)
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

void	*reset_buffer(char *buffer, size_t n)
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*output;
	char		*temp;
	// static int	counter;
	// static int	counter2;

	// counter++;
	// printf("counter = %i\n", counter);
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (reset_buffer(buffer, BUFFER_SIZE));
	bytes_read = 1;
	output = ft_sub_n_str(buffer, ft_strlen(buffer, '\n'));
	reset_buffer(buffer, ft_strlen(buffer, '\n'));
	while (bytes_read > 0 && !contain_nl(output))
	{
		// counter2++;
		// printf("counter2 = %i\n", counter2);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 )
		{
			free(ft_strjoin(&output, &temp));
			return (reset_buffer(buffer, BUFFER_SIZE));
		}
		// temp = NULL; 
		// if (counter2 < 15) 
		temp = ft_sub_n_str(buffer, bytes_read); // TODO: Gerer le cas où temp == NULL car maloc a pété
		reset_buffer(buffer, ft_strlen(temp, '\n'));
		output = ft_strjoin(&output, &temp);
	}
	return (output);
}
