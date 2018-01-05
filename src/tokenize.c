/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 01:37:42 by wutschkef         #+#    #+#             */
/*   Updated: 2018/01/04 20:17:28 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

static int	msh_count_words(char const *s, char *delims)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (ft_strchr(delims, s[i]))
			i++;
		if (!ft_strchr(delims, s[i]) && s[i] != '\0')
			count++;
		while (!ft_strchr(delims, s[i]) && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	msh_word_len(char const *s, char *delims)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (ft_strchr(delims, s[i]))
		i++;
	while (!ft_strchr(delims, s[i]) && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char		**msh_tokenize(char const *s, char *delims)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) *
						(msh_count_words(s, delims) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < msh_count_words(s, delims))
	{
		k = 0;
		if (!(s2[i] = ft_strnew(msh_word_len(&s[j], delims) + 1)))
			s2[i] = NULL;
		while (ft_strchr(delims, s[j]))
			j++;
		while (!ft_strchr(delims, s[j]) && s[j])
			s2[i][k++] = s[j++];
		s2[i][k] = '\0';
	}
	s2[i] = 0;
	return (s2);
}
