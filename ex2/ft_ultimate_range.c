/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:52:15 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/25 17:09:18 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	range = malloc(sizeof(int *) * (max - min));
	while (min < max)
	{
		range[i] = malloc(sizeof(int) * size);
		*range[i] = min;
		min++;
		i++;
	}
	if (!range)
		return (-1);
	return (size);
}
/*
void	print(int *range)
{
	int i = -1;
	while (++i < 5)
		printf("%d", range[i]);
}*/

int main(void)
{
	int min = 4;
	int max = 8;
	int **range;


	printf("%d", ft_ultimate_range(range, min, max));
	return (0);
}
