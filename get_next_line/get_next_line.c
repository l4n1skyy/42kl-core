#include "get_next_line.h"

static char	*update_stash(char *stash, char *new_stash);
static void	gnl_fail(char *buffer, char **stash);
static char	**ft_split_newline(char *stash);
static void	buffer_read(int fd, char **stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		**split;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	buffer_read(fd, &stash);
	split = ft_split_newline(stash);
	if (!split)
		free(stash);
	line = split[0];
	if (*line == '\0')
		return (NULL);
	stash = update_stash(stash, split[1]);
	free(split);
	return (line);
}

static void	buffer_read(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*new_stash;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		gnl_fail(buffer, stash);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			gnl_fail(buffer, stash);
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		if (!new_stash)
			gnl_fail(buffer, stash);
		free(*stash);
		*stash = new_stash;
	}
	free(buffer);
}

static char	*update_stash(char *stash, char *new_stash)
{
	free(stash);
	stash = new_stash;
	return (stash);
}

static void	gnl_fail(char *buffer, char **stash)
{
	free(buffer);
	free(*stash);
	*stash = NULL;
}

static char	**ft_split_newline(char *stash)
{
	char	**result;
	int		len;

	result = malloc(sizeof(char *) * 2);
	if (!result)
		return (NULL);
	len = ft_strchr(stash, '\n') - stash + 1;
	if (!len)
		len = 0;
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
