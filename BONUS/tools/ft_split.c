/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:01:50 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/09 09:38:14 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_len(const char *s, char c)
{
	int	existe;
	int	counter;

	existe = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s != c && existe == 0)
		{
			existe = 1;
			counter++;
		}
		else if (*s == c)
		{
			existe = 0;
		}
		s++;
	}
	return (counter);
}

static char	**mes_free(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size && array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
	return (NULL);
}

static char	*ft_findndcpy(char const *s, char c, int i)
{
	int		j;
	char	*str;
	int		len;

	j = 0;
	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	str = (char *)malloc((len + 1));
	if (!str)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_allocate(char const *s, char c, char **array, int wordscount)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < wordscount)
	{
		while (s[i] == c && s[i])
			i++;
		array[j] = ft_findndcpy(s, c, i);
		if (!array[j])
		{
			mes_free(array, wordscount);
			return (NULL);
		}
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	array[wordscount] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordscount;

	if (!s)
		return (NULL);
	wordscount = ft_len(s, c);
	array = (char **)malloc ((wordscount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (ft_allocate(s, c, array, wordscount));
}
