/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:49 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/24 18:49:48 by nboubeke         ###   ########.fr       */
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
        int     i;
        int     j;
        char     temp;

        i = 0;
        while (i < (length / 2))
        {
                j = length - i - 1;
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i++;
        }
	return (str);
}

char	*itoa(int nbr, char *base)
{
	char	*str;
	int	i;
	int	count;
	int	temp;
	int	rest;
	int b_len;
	
	b_len = base_len(base);
	temp = nbr;
	count = 0;
	if (temp == 0)
	{
	    str = malloc(2);
	    if (!str)
	        return NULL;
	    str[0] = base[0];
	    str[1] = '\0';
		return (str);
	}
	while (temp > 0)
	{
		temp = temp / b_len;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	i = 0;
	while (i < count)
	{
		rest = nbr % b_len;
		str[i] = base[rest];
		nbr /= b_len;
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
	int	i;

	i = 0;
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
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
	char *nbr = "        474565464";
	char *base_from = "0123456789";
	char *base_to = "0123456789ABCDEF";
	char *tab = ft_convert_base(nbr, base_from, base_to);
	int i = 0;

	while(tab[i])
	{
		printf("%c", tab[i]);
		i++;
	}
}
