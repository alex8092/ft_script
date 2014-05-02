/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:09 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:03:23 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "ft_script.h"

EXTERN_CHAR_ENVIRON;

char	*ft_getenv(char *name)
{
	char	**ptr;
	size_t	len;

	ptr = environ;
	len = ft_strlen(name);
	while (ptr && *ptr)
	{
		if (ft_strncmp(name, *ptr, len))
		{
			if ((*ptr)[len] == '=')
				return (*ptr + len + 1);
		}
		++ptr;
	}
	return (NULL);
}
