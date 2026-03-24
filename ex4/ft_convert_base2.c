/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:49 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/24 16:01:43 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	base_len(char *base);
int	is_valid_base(char *base);
int	index_in_base(char c, char *base);
int	atoi_base(char *str, char *base);

char   *reverse(char *str, int length)
{       
        char *reversed;
        int     i;
        int     j;
        int     temp;

        i = 0;
        while (i < (length / 2))
        {
                j = length - i - 1;
                temp = reversed[i];
                reversed[i] = reversed[j];
                reversed[j] = temp;
                i++;
        }
}

char	*itoa(int nbr, char *base)
{
	char	*str;
	int	i;
	int	count;
	int	temp;
	int	rest;

	temp = nbr;
	count = 0;
	if (temp == 0)
		return (0);
	while (temp > 0)
	{
		temp = temp / base_len(base);
		count++;
	}
	str = malloc(sizeof(char) * 400);
	i = 0;
	while (i < count)
	{
		rest = nbr % base_len(base);
		str[i] = base[rest];
		nbr /= base_len(base);
		i++;
	}
	reverse(str, count);
	str[i] = '\0';
	return (str);
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
	char *tab = ft_convert_base(nbr, base_from, base_to);
	int i = 0;

	while(tab[i])
	{
		printf("%c\n", tab[i]);
		i++;
	}
}
