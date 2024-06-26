/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:29:37 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/08/03 14:45:49 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen((char *)s);
	if (c == '\0')
		return (ft_strchr((char *)s, c));
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)s + (len - 1));
		len--;
	}
	return (NULL);
}
