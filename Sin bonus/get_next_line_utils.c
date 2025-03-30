/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:29:37 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/07 18:29:39 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	contador;

	contador = 0;
	while (str[contador] != '\0')
	{
		contador++;
	}
	return (contador);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	str = ft_zero(str, count * size);
	return (str);
}

void	*ft_zero(void *s, int size)
{
	char	*p;

	p = (char *)s;
	while (size > 0)
	{
		p[size - 1] = 0;
		size--;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)s + cont);
		cont++;
	}
	if ((char)c == '\0' && (char)s[cont] == '\0')
		return ((char *)s + cont);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr1;
	char	*ptr2;
	size_t	i;
	size_t	j;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	j = 0;
	str = ft_calloc(((ft_strlen(ptr1) + ft_strlen(ptr2)) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
