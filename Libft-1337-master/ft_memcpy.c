/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:25:01 by mahmidi           #+#    #+#             */
/*   Updated: 2019/10/18 11:22:03 by mahmidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return (dst);
}
