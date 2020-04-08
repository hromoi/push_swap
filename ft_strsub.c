/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:25:52 by yperra-f          #+#    #+#             */
/*   Updated: 2019/09/23 19:05:32 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;
	unsigned int	start1;

	i = 0;
	start1 = start;
	if (s == NULL || !*s)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start < (len + start1))
		s1[i++] = s[start++];
	s1[i] = '\0';
	return (s1);
}
