/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:14:36 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/11 14:50:50 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_int_strchr(const char *s, int c)
{
	int i;

	i = 0;
	c = (char)c;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char		*ft_strjoin_n(char *s1, char *s2, int n)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = (n > ft_strlen(s2) ? ft_strlen(s2) : n);
	i = 0;
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2 && s2[i] != '\0')
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char		*ft_strjoin_endl(char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	len1 = (s1 == NULL ? 0 : ft_strlen(s1));
	len2 = (ft_int_strchr(s2, '%') == -1 ?
	ft_strlen(s2) : ft_int_strchr(s2, '%'));
	i = 0;
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char		*print_nbr_base(long nb, char *base, int len_base, int len_res)
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
		res[len_res - 2 + sign] = base[nb % len_base];
		nb = nb / len_base;
		len_res--;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}

char		*ft_itoa_base(long nbr, char *base)
{
	char	*res;
	long	nb;
	int		len_base;
	int		len_res;

	if (!nbr || !base)
		return (NULL);
	nb = nbr;
	len_base = ft_strlen(base);
	len_res = 2;
	if (nb < 0)
		nb = -nb;
	while (nb / len_base > 0)
	{
		len_res++;
		nb = nb / len_base;
	}
	nb = nbr;
	res = print_nbr_base(nb, base, len_base, len_res);
	return (res);
}
