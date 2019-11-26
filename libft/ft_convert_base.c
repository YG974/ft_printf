/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:01:24 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/25 20:19:34 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		base_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_tnrvfrr(const char *str, char *base)
{
	int i;

	i = 0;
	while ((base_index(str[i], base) < 0) &&
			str[i] != '+' && str[i] != '-')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\r' && str[i] != '\f' && str[i] != '\v')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_strlen_strstr(char *str)
{
	int pos;
	int pos_find;

	pos = 0;
	if (str[pos] == '\0')
		return (0);
	while (str[pos] != '\0')
	{
		if (str[pos] == '-' || str[pos] == '+' || str[pos] == ' ' ||
			str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\r' ||
			str[pos] == '\v' || str[pos] == '\f')
			return (0);
		pos_find = pos + 1;
		while (str[pos_find] != '\0')
		{
			if (str[pos] == str[pos_find])
				return (0);
			pos_find++;
		}
		pos++;
	}
	if (pos < 2)
		return (0);
	return (pos);
}

char	*print_nbr_base(long nb, char *base, int len_base_to, int len_res)
{
	char	*res;
	int		sign;

	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	if (!(res = (char *)malloc(sizeof(char) * (len_res + sign))))
		return (NULL);
	res[len_res + sign - 1] = '\0';
	while (len_res > sign)
	{
		res[len_res - 2 + sign] = base[nb % len_base_to];
		nb = nb / len_base_to;
		len_res--;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	long	nb;
	int		len_base_to;
	int		len_res;

	if (nbr == NULL)
		return (NULL);
	if (!nbr || !base_to || !base_from)
		return (NULL);
	if (ft_strlen_strstr(base_from) < 2 || ft_strlen_strstr(base_to) < 2)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	len_base_to = ft_strlen_strstr(base_to);
	len_res = 2;
	if (nb < 0)
		nb = -nb;
	while (nb / len_base_to > 0)
	{
		len_res++;
		nb = nb / len_base_to;
	}
	nb = ft_atoi_base(nbr, base_from);
	res = print_nbr_base(nb, base_to, len_base_to, len_res);
	return (res);
}
