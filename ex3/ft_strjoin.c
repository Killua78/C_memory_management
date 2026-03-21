/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:19:59 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/20 12:59:20 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	full_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	fulltab;
	int 	seplen;

	i = 0;
	fulltab = 0;
	seplen = ft_strlen(sep) * (size - 1);
	while (*strs[i] < size)
	{
		fulltab += ft_strlen(strs[i]);
		i++;
	}
	return (fulltab + seplen);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	str = malloc(full_strlen(size, strs, sep) + 100);
	
	if (size == 0)
	{
		free (str);
		return NULL;
	}
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k] = strs[i][j];
			j++;
			k++;
			l = 0;
		}
		while (sep[l] != '\0' && i != (size - 1))
		{
			str[k] = sep[l];
			k++;
			l++;
		}
		i++;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
	char *strs[] = {"oui", "non", "bonjour", "help", "dormir", "faim"};
	char *sep = "sfffsdfs";
	
	printf("%s", ft_strjoin(6, strs, sep));
}
