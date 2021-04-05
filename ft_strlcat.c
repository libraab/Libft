/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:05:05 by abouhlel          #+#    #+#             */
/*   Updated: 2021/03/30 17:17:23 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dest[i])
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	j = -1;
	while (src[j])
	{
		if (j < dstsize - i - 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (i + ft_strlen(src));
}
/*#include <stdio.h>
int main()
{
	char a[] = "hello world";
	char b[] = "hola";
	int x = 2;
	printf("%zu\n", ft_strlcat(a, b, x));
	printf("%zu\n", strlcat(a, b, x));
}*/
