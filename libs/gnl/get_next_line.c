/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:34:41 by rdrevar           #+#    #+#             */
/*   Updated: 2026/04/23 17:35:16 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_update_stash(char *stash)
{
	char	*newline_pos;
	char	*new_stash;
	size_t	remaining_bytes;

	if (!stash)
		return (free(stash), NULL);
	newline_pos = ft_strchr(stash, '\n');
	if (!newline_pos)
		return (free(stash), NULL);
	newline_pos++;
	remaining_bytes = ft_strlen(newline_pos);
	if (remaining_bytes == 0)
		return (free(stash), NULL);
	new_stash = malloc(remaining_bytes + 1);
	if (!new_stash)
		return (free(stash), NULL);
	ft_memcpy(new_stash, newline_pos, remaining_bytes);
	new_stash[remaining_bytes] = 0;
	free(stash);
	return (new_stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*newline_pos;
	size_t	bytes_to_copy;

	if (!stash || *stash == '\0')
		return (NULL);
	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		bytes_to_copy = newline_pos - stash + 1;
	else
		bytes_to_copy = ft_strlen(stash);
	line = malloc(bytes_to_copy + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, bytes_to_copy);
	line[bytes_to_copy] = 0;
	return (line);
}

char	*ft_expand_stash(char *stash, char *buffer, ssize_t bytes_read)
{
	ssize_t	stash_len;
	char	*new_stash;

	stash_len = 0;
	if (stash)
		stash_len = ft_strlen(stash);
	new_stash = malloc(stash_len + bytes_read + 1);
	if (!new_stash)
		return (free(stash), NULL);
	if (stash)
	{
		ft_memcpy(new_stash, stash, stash_len);
		free(stash);
	}
	ft_memcpy(new_stash + stash_len, buffer, bytes_read);
	new_stash[stash_len + bytes_read] = '\0';
	return (new_stash);
}

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			stash = ft_expand_stash(stash, buffer, bytes_read);
			if (!stash)
				return (free(buffer), NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	else
		stash = ft_update_stash(stash);
	return (line);
}
