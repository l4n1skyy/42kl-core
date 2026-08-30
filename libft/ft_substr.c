/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <a@b.c> */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	copy_len;
	size_t	i;
	char	*dst;

	str_len = ft_strlen(s);
	copy_len = 0;
	if (start < str_len)
	{
		copy_len = str_len - start;
		if (copy_len > len)
			copy_len = len;
	}
	dst = malloc(copy_len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
