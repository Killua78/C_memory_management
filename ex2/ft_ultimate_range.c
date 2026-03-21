/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:52:15 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/19 13:47:00 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	i = 0;
	*range = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		*range[i] = min;
		min++;
		i++;
	}
	if (!range)
		return (-1);
	return (max - min);
}
