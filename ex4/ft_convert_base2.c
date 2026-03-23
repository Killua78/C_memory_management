/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:49 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/23 19:18:19 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	base_len(char *base);
int	is_valid_base(char *base);
int	index_in_base(char c, char *base);
int	atoi_base(char *str, char *base);

char	itoa(int nbr, char *base)
{
	char	*str;
	int	i;
	int	count;

	count = 0;
	if (nbr == 0)
		return ('0');
	while (nbr > 0)
	{
		nbr = nbr % base_len(base);
		count++;
	}
	str = malloc(sizeof(char) * count);
	i = 0;
	while (i < count)
	{
		nbr = nbr % base_len(base);
		str[i] = base[nbr];
		i++;
	}
	return (*str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	atoi;
	char	*final;

	if (!(is_valid_base(base_from) || is_valid_base(base_to)))
	{
		return (0);
	}
	else
	{
		atoi = atoi_base(nbr, base_from);
		return (itoa(atoi, base_to));
	}
}

int main(void)
{
	char *nbr = "54";
	char *base_from = "0123456789";
	char *base_to = "0123456789ABCDEF";


}
