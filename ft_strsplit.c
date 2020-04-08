/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:02:10 by yperra-f          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:13 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_wcount(char const *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == 32 || *s == 9)
			s++;
		if (*s != 32 && *s != 9 && *s != '\0')
			i++;
		while (*s != 32 && *s != 9 && *s != '\0')
			s++;
	}
	return (i);
}

static size_t	ft_length(const char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != '\0' && s[i] != 32 && s[i] != 9)
	{
		j++;
		i++;
	}
	return (j);
}

char		**ft_free(char **s, int j)
{
	int i;

	i = 0;
	while (i < j)
		free(s[i++]);
	free(s);
	s = NULL;
	return (NULL);
}

char			**ft_strsplit(const char *s)
{
	char			**split;
	unsigned int	i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	k = ft_wcount(s);
	if (!(split = (char **)malloc((k + 1) * sizeof(char *))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == 32 || s[i] == 9))
			i++;
		if (s[i] != '\0' && !(split[j] = ft_strsub(s, i, ft_length(s, i))))
			return (ft_free(split, j));
		if (s[i])
			j++;
		while (s[i] != '\0' && s[i] != 32 && s[i] != 9)
			i++;
	}
	split[j] = NULL;
	return (split);
}
