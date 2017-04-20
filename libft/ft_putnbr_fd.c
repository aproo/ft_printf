/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakahon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 21:05:55 by vmakahon          #+#    #+#             */
/*   Updated: 2017/01/01 21:05:55 by vmakahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(intmax_t nb, int fd)
{
	int		max;

	max = nb;
	if (max == (-2147483648))
		nb = -214748364;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + '0', fd);
	if (max == -2147483648)
		ft_putchar_fd('8', fd);
}
