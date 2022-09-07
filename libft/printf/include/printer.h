/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:22:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2022/08/05 13:41:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "ft_printf.h"
# include "../../libft.h"

# define BINARY "01"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

typedef int	(*t_out)(t_param *, va_list);

t_out	*conversion_array(void);
void	init_printer(void);

int		out_char(t_param *spec, va_list args);
int		out_string(t_param *spec, va_list args);
int		out_pointer(t_param *spec, va_list args);
int		out_signed(t_param *spec, va_list args);
int		out_unsigned(t_param *spec, va_list args);
int		out_percent(t_param *spec, va_list args);

int		put_format(t_param *spec, va_list args);
int		put_padding(t_param *spec);
int		put_string(const char *string, int length);
int		put_number_justified(t_param *spec, char *string, int strlen);
void	set_number_precision(t_param *spec, int strlen);
char	*ft_itoa_base(unsigned long nbr, char *nbr_sys);

#endif
