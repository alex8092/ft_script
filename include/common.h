/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 05:00:24 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:00:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_getenv(char *name);

void	ft_bzero(void *ptr, size_t n);
void	ft_putstr(char *str);

int		ft_strncmp(char *s1, char *s2, size_t n);

#endif
