/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:24:10 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/30 16:58:01 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	w_l(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	size_t	i;
	size_t	l;
	size_t	w_i;

	if (!s)
		return (NULL);
	l = w_c(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		while (*s == c && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * w_l(s, c) + 1);
		w_i = 0;
		while (*s != c && *s != '\0')
			r[i][w_i++] = *s++;
		r[i][w_i] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}

long	ft_atoi(const char *str)
{
	int		neg_value;
	int		i;
	long	value;

	i = 0;
	neg_value = 1;
	value = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg_value *= -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		value = value * 10 + (str[i++] - 48);
	}
	return (value * neg_value);
}

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*str2 == '\0' || str2 == NULL)
		return ((char *) str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str2[j] == str1[i + j] && i + j < n)
		{
			if (str2[j + 1] == '\0')
			{
				return ((char *)str1 + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
