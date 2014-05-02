/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptsname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:10 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:10 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"

char	*ft_ptsname(int fd)
{
	static char		name[128];

	if (ioctl(fd, TIOCPTYGNAME, name) < 0)
		return (NULL);
	if (access(name, F_OK) < 0)
		return (NULL);
	return (name);
}
