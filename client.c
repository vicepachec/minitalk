/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:05:33 by vpacheco          #+#    #+#             */
/*   Updated: 2022/06/07 14:35:38 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char c, int pid)
{
	int		i;
	char	signal;

	signal = 0;
	i = 8;
	if (!c)
		c = '\n';
	while (--i >= 0)
	{	
		signal = ((c >> i & 1) + 48);
		if (signal == '0')
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (signal == '1')
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "Wrong number of arguments!\n", 30);
		return (0);
	}
	(void)argc;
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		char_to_binary(argv[2][i], pid);
			i++;
	}
	char_to_binary(argv[2][i], pid);
	return (0);
}
