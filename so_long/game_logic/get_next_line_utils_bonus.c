/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:33:12 by kbrauer           #+#    #+#             */
/*   Updated: 2023/11/19 17:45:39 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*fill_new_str(char *new_str, char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		new_str[i + k] = s2[k];
		k++;
	}
	new_str[i + k] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		len;

	if (!s1)
	{
		s1 = (char *) malloc (sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *) malloc (len * sizeof(char) + 1);
	if (!new_str)
		return (free(s1), NULL);
	return (fill_new_str(new_str, s1, s2));
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}
