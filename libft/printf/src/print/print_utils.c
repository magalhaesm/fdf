/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/05 12:27:23 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/printer.h"

static int	nbrlen(unsigned long n, unsigned long base);

int	put_padding(t_param *spec)
{
	int	written;

	written = 0;
	while (spec->width > 0)
	{
		written += put_string(&spec->pad, 1);
		spec->width--;
	}
	return (written);
}

void	set_number_precision(t_param *spec, int strlen)
{
	if (spec->precision < strlen)
		spec->precision = 0;
	else
		spec->precision -= strlen;
}

char	*ft_itoa_base(unsigned long nbr, char *nbr_sys)
{
	char	*str;
	int		len;
	int		base;

	base = ft_strlen(nbr_sys);
	len = nbrlen(nbr, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nbr_sys[nbr % base];
		nbr /= base;
	}
	return (str);
}

static int	nbrlen(unsigned long n, unsigned long base)
{
	if (n < base)
		return (1);
	n /= base;
	return (nbrlen(n, base) + 1);
}
