/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:10 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:10 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int	ft_init(t_script *sc)
{
	if (FT_TCGETATTR(0, &sc->line) < 0)
		return (ft_puterror("Unable to get attribute\n", -1));
	if (ioctl(0, TIOCGWINSZ, &sc->winp) < 0)
		return (ft_puterror("Unable to get attribute\n", -2));
	sc->line.c_cc[VMIN] = 1;
	sc->line.c_cc[VTIME] = 0;
	sc->line.c_lflag &= ~(ICANON | ECHO | ISIG);
	ioctl(0, TIOCSETA, &sc->line);
	sc->outfile = "typescript";
	sc->flag_c = NULL;
	sc->flag_a = 0;
	sc->flag_q = 0;
	sc->flag_t = 0;
	sc->flag_k = 0;
	return (0);
}
