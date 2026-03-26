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
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	full_strlen(int size, char **strs, char *sep)
{
	int	i;
	int fulltab;
	int 	seplen;

	i = 0;
	fulltab = 0;
	seplen = 0;
	while (i < size)
	{
		fulltab += ft_strlen(strs[i]);
		i++;
	}
	
	if (size > 1)
	    seplen = ft_strlen(sep) * (size - 1);
	return (fulltab + seplen);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int	i;
	int	j;
	int	k;
	int	l;

	if (size == 0)
	{
	    str = malloc(1);
	    if(!str)
	        return NULL;
		str[0] = '\0';
		return (str);
	}
	str = malloc(full_strlen(size, strs, sep) + 1);
	if(!str)
	    return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[k++] = strs[i][j++];
		}
		if (i < size - 1)
		{
		   l = 0;
		   while (sep[l])
		    str[k++] = sep[l++];
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

int main(void)
{
	char *strs[] = {"oui", "non", "bonjour", "help", "dormir", "faim"};
	char *sep = "     ";
	
	printf("%s", ft_strjoin(2, strs, sep));
}
