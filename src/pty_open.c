/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:08:49 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int		pty_open(t_script *sc)
{
	int	oflag;

	if ((sc->fd_master = open("/dev/ptmx", O_RDWR | O_NOCTTY)) < 0)
		return (ft_puterror("Unable to open pty master\n", -1));
	ft_grantpt(sc->fd_master);
	ft_unlockpt(sc->fd_master);
	if ((sc->fd_slave = open(ft_ptsname(sc->fd_master), O_RDWR | O_NOCTTY)) < 0)
		return (ft_puterror("Unable to open pty slave\n", -2));
	sc->line.c_lflag |= ECHO;
	ioctl(sc->fd_slave, TIOCSETA, &sc->line);
	ioctl(sc->fd_slave, TIOCSWINSZ, &sc->winp);
	oflag = (!sc->flag_a) ? O_TRUNC : O_APPEND;
	oflag |= O_WRONLY | O_CREAT | O_NONBLOCK;
	if ((sc->fd_file = open(sc->outfile, oflag, 0700)) < 0)
		return (ft_puterror("Unable to open output file\n", -3));
	return (0);
}
