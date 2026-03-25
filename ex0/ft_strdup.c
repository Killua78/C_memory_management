/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:30:18 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/25 11:20:15 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		i;

	i = -1;
	duplicate = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!duplicate)
		return NULL;
	while (src[++i])
		duplicate[i] = src[i];
	duplicate[i] = '\0';
	return (duplicate);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s", ft_strdup(""));
}*/
