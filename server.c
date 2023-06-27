/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:48:04 by vpacheco          #+#    #+#             */
/*   Updated: 2022/06/06 13:05:59 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int sig)
{
	static int	binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int	i = 0;
	static char	sum = 0;

	if (sig == SIGUSR1)
	{
		i++;
	}
	if (sig == SIGUSR2)
	{
		sum = sum + binary[i];
		i++;
	}
	if (i >= 8)
	{
		write(1, &sum, 1);
		i = 0;
		sum = 0;
	}
}

void	putnbr(pid_t n)
{
	if (n > 0)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(void)
{
	pid_t		pid;

	pid = getpid();
	putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	while (1)
	{
		pause();
	}
	return (0);
}
