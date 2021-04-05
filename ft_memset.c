/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:01:12 by abouhlel          #+#    #+#             */
/*   Updated: 2021/04/02 17:06:03 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*y;

	y = (unsigned char *)b;
	while (len > 0)
	{
		*y = (unsigned char)c;
		y++;
		len--;
	}
	return (b = (void *)y);
}
