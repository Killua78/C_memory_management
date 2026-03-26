/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:17:46 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/24 18:10:40 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	count;
	
	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (count % 2 == 1)
		return (-nbr);
	else
		return (nbr);
}

#include <stdio.h>
int main(void)
{
	char *str = "-+-----++++++45684ab45";
	printf("%d", ft_atoi(str));
}
