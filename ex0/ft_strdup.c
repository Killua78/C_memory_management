/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:30:18 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/19 12:03:32 by nboubeke         ###   ########.fr       */
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

	i = 0;
	duplicate = malloc(sizeof(int) * ft_strlen(src));
	while (src[i] != '\0')
	{
		duplicate[i] = src[i];
		i++;
	}
	return (duplicate);
}

#include <stdio.h>
int main(void)
{
	printf("%s", ft_strdup("OHAYO"));
}
