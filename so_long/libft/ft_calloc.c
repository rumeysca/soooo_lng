/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:44:24 by rcan              #+#    #+#             */
/*   Updated: 2023/10/24 18:21:00 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	memnbr;

	memnbr = count * size;
	str = (void *)malloc(memnbr);
	if (!str)
	{
		return (0);
	}
	ft_bzero(str, memnbr);
	return (str);
}
