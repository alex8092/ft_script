/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:09 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:37 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"

int		ft_parse_flag(char *arg, t_script *sc)
{
	int		i;
	int		active;

	i = 1;
	active = arg[0] == '-' ? 1 : 0;
	while (active && arg[i])
	{
		if (arg[i] == 'a')
			sc->flag_a = 1;
		else if (arg[i] == 'k')
			sc->flag_k = 1;
		else if (arg[i] == 'q')
			sc->flag_q = 1;
		else
			break ;
		++i;
	}
	return (active);
}
