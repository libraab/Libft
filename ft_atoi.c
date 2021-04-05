/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:53:42 by abouhlel          #+#    #+#             */
/*   Updated: 2021/04/02 11:32:50 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_atoi(char *str)
{
	long long int	a;
	long long int	i;
	int				b;

	a = 0;
	b = 1;
	i = 0;
	if (ft_strlen(str) > 13)
		return (-1);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\t' || str[i] == '\r')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = b * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	return (a * b);
}
/*#include <stdlib.h>
#include <stdio.h>
int main()
{
	 char a[] = "1844674407375";
	 printf("%d\n", ft_atoi(a));
	 printf("%d\n\n", atoi(a));
 }*/
