/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getshell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 04:59:10 by amerle            #+#    #+#             */
/*   Updated: 2014/05/02 04:59:10 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"
#include "common.h"

char	*ft_getshell(void)
{
	char	*shell;

	shell = ft_getenv("SHELL");
	if (!shell || !*shell || access(shell, F_OK) < 0)
		return ("/bin/sh");
	return (shell);
}
