/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:08:57 by jschneid          #+#    #+#             */
/*   Updated: 2022/08/18 15:55:44 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	if (size > 0 && (INT_MAX / size) < count)
		return (NULL);
	rtn = malloc(count * size);
	if (rtn == NULL)
		return (NULL);
	ft_memset(rtn, '\0', (count * size));
	return (rtn);
}
