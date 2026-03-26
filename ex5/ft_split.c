/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:25:58 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/26 16:47:07 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LA BEEETE
#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		else
			i++;
	}
	return (0);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], charset))
	{
		i++;
	}
	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_sep(str[i], charset))
	{
		i++;
	}
	if (!is_sep(str[0], charset))
		count = 1;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && is_sep(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	i = 0;
	k = 0;
	while (str[k])
	{
		j = 0;
		while (is_sep(str[k], charset))
			k++;
		tab[i] = malloc(sizeof(char) * (word_len(&str[k], charset) + 1));
		while (str[k] && !is_sep(str[k], charset))
		{
			tab[i][j++] = str[k++];
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
#include <stdio.h>
int main(void)
{
	char *str = "jveux passer split pitie";
	char *charset = " ";
	char **tab = ft_split(str, charset);

	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
