/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:07:13 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/26 13:02:45 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	range = malloc(sizeof(int) * (max - min) + 1);
	while (min < max)
	{
		range[i] = min;
		min++;
		i++;
	}
	range[i] = '\0';
	return (range);
}

#include <stdio.h>
int main(void)
{
	int min = 0;
	int max = 14;
	int *tab;
	int i = 0;

	tab = ft_range(min, max);
	while(i < (max - min))
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
