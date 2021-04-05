/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:23:46 by abouhlel          #+#    #+#             */
/*   Updated: 2021/04/02 17:20:40 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static	int			ft_itoa_size(int n)
{
	int				size;
	int				neg;
	size = 0;
	neg = 0;
	if (n < 0 && n > -2147483648)
	{
		neg = 1;
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}
char				*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;
	int				neg;
	unsigned int	tmp;
	size = ft_itoa_size(n);
	neg = (n < 0 ? 1 : 0);
	i = 1;
	if (!((str = (char *)malloc(sizeof(char) * ft_itoa_size(n) + 1))))
		return (NULL);
	tmp = (n < 0 ? -n : n);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (neg)
		*str = '-';
	str[size] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main()
{
	long int x = -2147483647;
	printf("%s", ft_itoa(x));
}*/
