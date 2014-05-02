/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pty_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:11 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 05:14:27 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include <signal.h>

static void	signhandler_chld(int sig)
{
	int	ret;

	(void)sig;
	waitpid(script_singleton()->child_pid, &ret, 0);
	script_singleton()->exit = 1;
}

static void	signhandler_winch(int sig)
{
	struct winsize	winp;

	(void)sig;
	if (ioctl(0, TIOCGWINSZ, (char *)&winp) < 0
		|| ioctl(script_singleton()->fd_master, TIOCSWINSZ, (char *)&winp) < 0
		|| kill(-1, SIGWINCH) == -1)
		return ;
	pty_signals();
}

void		pty_signals(void)
{
	signal(SIGCHLD, signhandler_chld);
	signal(SIGWINCH, signhandler_winch);
}
