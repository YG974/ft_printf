/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spadding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:46:16 by ygeslin           #+#    #+#             */
/*   Updated: 2020/02/14 12:17:08 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spadding(t_printf *s)
{
	char	*pad;

	s->tmp_len = (ft_strlen(s->tmp) > s->width ? s->width : ft_strlen(s->tmp));
	if (!(pad = (char *)ft_calloc((s->width - s->tmp_len + 1), sizeof(char))))
		return ;
	if ((s->width > 0 && s->precision >= 0) || s->wstar == 1)
		pad = ft_memset(pad, ' ', s->width - s->tmp_len);
	if ((s->minus == 1 || s->neg_width == 1))
		s->tmp = ft_strjoin(s->tmp, pad);
	else
		s->tmp = ft_strjoin(pad, s->tmp);
	s->str = ft_strjoin(s->str, s->tmp);
	free(pad);
	return ;
}

void		ft_sprecision(t_printf *s)
{
	char *pad;

	if (!(pad = (char *)ft_calloc(1, sizeof(char))))
		return ;
	if (s->precision < 0)
	{
		s->precision = 1;
		s->pstar = 1;
	}
	if ((s->pdot == 1 || s->dot == 1 || s->pstar) && s->neg_precision == 0)
		s->tmp = ft_strjoin_n(pad, s->tmp, s->precision);
	return ;
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (!(s2 && s1))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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
	str[len1 + len2] = '\0';
	free(s2);
	return (str);
}

char		*ft_strjoin2_n(char *s1, char *s2, int n)
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
	free(s2);
	return (str);
}

