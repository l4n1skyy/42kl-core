/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	size_new;

	len_s = (size_t)ft_strlen((char *)src);
	len_d = (size_t)ft_strlen(dst);
	size_new = size;
	if (size_new == 0)
		return (len_s);
	while (*dst && size_new--)
		dst++;
	if (*dst)
		return (len_s + size);
	while (*src && --size_new)
		*dst++ = *src++;
	*dst = '\0';
	return (len_s + len_d);
}
