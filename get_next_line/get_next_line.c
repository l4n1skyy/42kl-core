#include "get_next_line.h"
static char *update_stash(char *stash, char *new_stash);
static int read_chunk(int fd, char *buffer, ssize_t *bytes_read);
static char *gnl_fail(char *buffer, char **stash);
static char **ft_split_newline(char *stash);

char *get_next_line(int fd)
{
	static char *stash;
	char *buffer;
	ssize_t bytes_read;
	char *new_stash;
	char **split;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (gnl_fail(buffer, &stash));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		if (!read_chunk(fd, buffer, &bytes_read))
			return (gnl_fail(buffer, &stash));
		new_stash = ft_strjoin(stash, buffer);
		if (!new_stash)
			return (gnl_fail(buffer, &stash));
		stash = update_stash(stash, new_stash);
		if (ft_strchr(stash, '\n'))
		{
			split = ft_split_newline(stash);
			if (!split)
				return (gnl_fail(buffer, &stash));
			line = split[0];
			stash = update_stash(stash, split[1]);
			free(split);
			free(buffer);
			return (line);
		}
	}
	free(buffer);
	buffer = stash;
	stash = NULL;
	if (!*buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

static char *update_stash(char *stash, char *new_stash)
{
	free(stash);
	stash = new_stash;
	return (stash);
}

static char *gnl_fail(char *buffer, char **stash)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
	return (NULL);
}

static int read_chunk(int fd, char *buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (0);
	buffer[*bytes_read] = '\0';
	return (1);
}

static char **ft_split_newline(char *stash)
{
	char **result;
	int len;

	result = malloc(sizeof(char *) * 2);
	if (!result)
		return (NULL);
	len = ft_strchr(stash, '\n') - stash + 1;
	result[0] = ft_substr(stash, 0, len);
	result[1] = ft_substr(stash, len, ft_strlen(stash) - len);
	if (!result[0] || !result[1])
	{
		free(result[0]);
		free(result[1]);
		free(result);
		return (NULL);
	}
	return (result);
}
