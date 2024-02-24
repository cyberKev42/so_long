/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:32:48 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/22 18:15:21 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	int		count_str;
	char	*final_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	count_str = ft_strlen(str);
	final_str = (char *) malloc (sizeof(char) * (count_str - i + 1));
	if (!final_str)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		final_str[j++] = str[i++];
	final_str[j] = 0;
	free(str);
	return (final_str);
}

static	char	*ft_get_new_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	new_str = (char *) malloc (sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\n';
	i++;
	return (new_str[i] = 0, new_str);
}

static	char	*ft_read_str(int fd, char *str)
{
	char	*buf;
	int		bufrd;

	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (str)
			free(str);
		return (NULL);
	}
	bufrd = 1;
	while (bufrd > 0)
	{
		bufrd = read(fd, buf, BUFFER_SIZE);
		if (bufrd < 0)
			return (free(buf), free(str), NULL);
		buf[bufrd] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
		if (!str)
			return (free(buf), NULL);
	}
	free(buf);
	return (str);
}

int	get_next_line(int fd, char **new_line)
{
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read_str(fd, str[fd]);
	if (!str[fd])
		return (0);
	*new_line = ft_get_new_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (1);
}
/*
int	main(void)
{
	int	i;
	int fd1;
	int fd2;
	char *gnl;
	
	i = 200;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	
	
	while (i)
	{
		gnl = get_next_line(fd1);
		printf("get_next_line: %s\n", gnl);
		free(gnl);
		gnl = get_next_line(fd2);
		printf("get_next_line: %s\n", gnl);
		free(gnl);
		i--;
	}
	close(fd1);
	close(fd2);
}
*/
