/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:22 by rcan              #+#    #+#             */
/*   Updated: 2023/10/24 20:10:22 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	str_len;
	size_t	end;
	size_t	i;

	i = start;
	str_len = ft_strlen(s);
	end = 0;
	if (!s)
		return (NULL);
	if (start < str_len)
		end = str_len - start;
	if (end > len)
		end = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc((sizeof(char) * (end + 1)));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, end + 1);
	return (dest);
}
