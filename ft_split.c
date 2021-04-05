/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:05:08 by abouhlel          #+#    #+#             */
/*   Updated: 2021/04/02 11:50:46 by abouhlel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strs_nb(char const *s, const char *delimiters)
{
	size_t	i;
	size_t	x;

	if (!s[0] || !delimiters)
		return (0);
	i = 0;
	x = 0;
	while (s[i] && ft_strchr(delimiters, s[i]))
		i++;
	while (s[i])
	{
		if (ft_strchr(delimiters, s[i]))
		{
			x++;
			while (s[i] && ft_strchr(delimiters, s[i]))
				i++;
			continue ;
		}
		i++;
	}
	if (!ft_strchr(delimiters, s[i - 1]))
		x++;
	return (x);
}

static void	ft_get_next_str(char **next_s, size_t *s_len, const char *delimiters)
{
	size_t	i;

	*next_s += *s_len;
	*s_len = 0;
	i = 0;
	while (**next_s && ft_strchr(delimiters, **next_s))
		(*next_s)++;
	while ((*next_s)[i])
	{
		if (ft_strchr(delimiters, (*next_s)[i]))
			return ;
		(*s_len)++;
		i++;
	}
}

char	**ft_freed(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, const char *delimiters)
{
	char	**tab;
	char	*next_str;
	size_t	next_str_len;
	size_t	nb_strs;
	size_t	i;

	nb_strs = ft_strs_nb(s, delimiters);
	tab = malloc(sizeof(char *) * (nb_strs + 1));
		if (!tab)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, delimiters);
		tab[i] = malloc(sizeof(char) * (next_str_len + 1));
			if (!tab)
			return (ft_freed(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(void)
{
	char	**tab;
	size_t	i;

	i = 0;
	tab = ft_split(", hello, baby  .9..  you ,,,,  are,,,awsome,, , ", ", ");
	if (!tab[0])
		ft_putendl_fd("ok\n", 1);
	while (tab[i] != NULL)
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
}
