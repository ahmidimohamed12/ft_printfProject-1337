/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:09:21 by mahmidi           #+#    #+#             */
/*   Updated: 2019/10/18 12:09:23 by mahmidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"


char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		++i;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
