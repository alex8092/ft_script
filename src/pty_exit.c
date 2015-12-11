/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:11 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"

void	pty_exit(t_script *sc)
{
	close(sc->fd_file);
	if (!sc->flag_q)
	{
		ft_putstr("\nScript done, output file is ");
		ft_putstr(sc->outfile);
		ft_putstr("\n");
	}
	close(sc->fd_master);
	sc->line.c_lflag |= (ICANON | ECHO | ISIG);
	ioctl(0, TIOCSETA, &sc->line);
	_exit(0);
}
