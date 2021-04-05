/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:52:36 by abouhlel          #+#    #+#             */
/*   Updated: 2021/03/30 17:09:54 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
/*#include <stdio.h>
int main ()
{
	char a[] = "HdhvqcjdhvcqjohO";
	char b[] = "HeLjbckqsbjckdlO";
	printf("%d", ft_strcmp(b, a));
	printf("\n");
	printf("%d", strcmp(b, a));
}*/
