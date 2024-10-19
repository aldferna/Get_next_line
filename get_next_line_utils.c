/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianafernandez <adrianafernandez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:34:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/10/17 21:16:27 by adrianafern      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	x;

	x = ft_strlen((char *)s);
	if (start > x)
		return (NULL); //cambio
	if ((x - start) < len)
		len = x - start;
	str_new = (char *)malloc((len + 1) * (sizeof(char)));
	if (!str_new)
		return (NULL);
	ft_strlcpy(str_new, s + start, len + 1);
	return (str_new);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	int		n;

 	n = nmemb * size;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (n > 0)
	{
		array[n - 1] = '\0';
		n--;
	}
	return (array);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		x;

	i = 0;
	x = ft_strlen((char *)src);
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t		len;
	int			i;
	int			len_dest;

	if (!s1 || !s2)
		return (NULL);
	len_dest = ft_strlen((char *)s1);
	len = len_dest + ft_strlen((char *)s2);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (free(new_str), NULL);
	ft_strlcpy(new_str, s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(new_str + len_dest, s2, ft_strlen((char *)s2) + 1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	return ((char *)&s[i]);
}
