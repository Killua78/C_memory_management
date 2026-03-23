/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboubeke <nboubeke@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:29 by nboubeke          #+#    #+#             */
/*   Updated: 2026/03/23 18:40:53 by nboubeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;

	i = 0;
	if (base_len(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == base[i + 1] || base[i] == '\n')
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == ' ' || base[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int	index_in_base(char c, char *base)
{
	int	i;
	
	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '-')
			count++;
		i++;
	}	
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		else
			j = j * base_len(base) + index_in_base(str[i], base);
		i++;
	}
	if (count % 2 == 0)
		return (j);
	else
		return (-j);
}
