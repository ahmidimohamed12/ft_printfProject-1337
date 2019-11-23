/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:50:29 by mahmidi           #+#    #+#             */
/*   Updated: 2019/10/18 12:47:14 by mahmidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "libft.h"


char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*string;

	if (!(string = ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		string[i++] = '\0';
	return (string);
}
